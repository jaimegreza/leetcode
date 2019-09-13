#include <iostream>
#include <vector>

using namespace std;

class ArraysTest
{
public:
    ArraysTest(){};

    int addTwoNumbersInArray(vector<int> input1, vector<int> input2)
    {


        return input1[0] + input2[0];
    }

    int lengthOfNumberInArray(vector<int> input, int num)
    {
        int exist = binarySearch(input, num);

        if (exist < 0) return 0;


        int left = leftIndexOfNumberInArray(input,exist,num);
        int right = rightIndexOfNumberInArray(input,exist,num);

        return (right-left + 1);

    }


    int binarySearch(vector<int> input, int search)
    {
        int low = 0;
        int high = input.size() -1;
        return binarySearch(input,search,low,high);
    }

private:
    int leftIndexOfNumberInArray(vector<int> input, int index, int num)
    {

        if (index == 0) return index;

        int found = index;

        while (found)
        {
            found = binarySearch(input,num,0, found);

            if (found == 0)
                return 0;
            
            if (input[found-1] != num)
                return found;
            else    
                found = found-1;
        }

        return index;
    }

    int rightIndexOfNumberInArray(vector<int> input, int index, int num)
    {

        if (index == input.size()-1) return index;
                
        int found = index;
        
        while (found)
        {
            found = binarySearch(input,num,found, input.size()-1);
        
            if (found == input.size()-1)
                return input.size()-1;
                    
            if (input[found+1] != num)
                return found;
            else    
                found = found+1;
            
        }
        
        return index;
        
    }

  
    int binarySearch(vector<int> input, int search, int low, int high)
    {

        int mid;

        while ( low <= high)
        {   
            mid = low+((high-low) /2);

            if (input[mid] == search) {
                return mid;
            } 
            else if (input[mid] < search)
            {
                low = mid + 1;
            } 
            else
            {
                high = mid - 1;
            }
        }

        return -1;   
    }

};

int main()
{
    ArraysTest test;

     //vector<int> input1 = {1,3,5,7,8,8,8,8,9,20, 30, 50};
//   vector<int> input1 = {1,8,8,8,9};
   // vector<int> input1 = {2};
   vector<int> input1 = {8,8,8};
   vector<int> input2 = {2};
    
    //int result = test.addTwoNumbersInArray(input1, input2);
    int result = test.lengthOfNumberInArray(input1, 8);
  //  int result = test.binarySearch(input1, 18);
    cout << result << endl;
    return 0;
}