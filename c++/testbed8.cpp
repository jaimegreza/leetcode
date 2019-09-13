#include <iostream>
#include <vector>
#include <set>
#include <array>

using namespace std;

class API
{
public: 
    API(){};

    int Read4k(char * buf)
    {

        const char * Fs = "FFFF";
        const char * As = "AAAA";
        static int size = 9;

        if (size > 0)
        {

            int read = 4;

            if (read > size)
            {

                memcpy(buf, As, size);
                read = size;
                size = 0;
            }
            else
            {
                 memcpy(buf, Fs, read);
                 size = size - read;
 
            }

            return read;
        }
        else 
            return 0;
    }


};

class ManageBuffer
{
private:


public:
        ManageBuffer(){};

        int readResource(char * buf, int n)
        {
            static char * cache  = new char(4);
            static int cachePtr = -1; // 0,1,2,3  (3 is last char)
            static int read = 0; // chars read in api call

            API api;

            int total_read = 0;
            int bufptr = 0;

            while (n > 0)
            {

                if (cachePtr == -1)
                {
                    read = api.Read4k(cache);
                    
                    if (read > 0)
                        cachePtr = 0;
                    else
                        return total_read;
                }

                // [ , . . . . . . . ]  
                // [ . . . , . . . . ]  
                // [ , . . . . .     ]  
                // [ . . , . . .     ]  

                // calculate copy amt and availability

                int available = read - cachePtr;
                
                int cpy_amt = available;


                // update copy amt for request less than available
                
                if (n <  available)
                {
                    cpy_amt = n;
                }
                
                // perform cache transfer
                memcpy(buf+bufptr,cache+cachePtr,cpy_amt);

                // update response state
                bufptr += cpy_amt;

                // update cache state
                available -= cpy_amt;

                if (available == 0)
                    cachePtr = -1;
                else
                    cachePtr = cachePtr + cpy_amt;
                
                // update response state
                total_read += cpy_amt;

                n = n - cpy_amt;
                    
            }

            return total_read;
            
        }


};


int main()
{
 
    ManageBuffer buf;

    char * buffer = new char(5);
    char * buffer2 = new char(4);
    
    int n = buf.readResource(buffer, 5);

    printf("chars read: %d \r\n", n);

    printf("buffer: %s \r\n ", buffer);
    
    int m = buf.readResource(buffer2, 4);
    
    printf("chars read 2: %d \r\n", m);
    
    printf("buffer2: %s \r\n ", buffer2);

        

    return 0;
}