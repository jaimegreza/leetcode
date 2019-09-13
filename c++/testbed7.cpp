#include <iostream>
#include <vector>
#include <set>
#include <array>

using namespace std;

class SubSets
{
public:
     SubSets(){};

    void PrintAllSubSets(vector<int> input)
    {

        for (int i =0; i < input.size();i++)
        {

            for (int j = 0; j < input.size();j++)
            {
                if (i != j)
                    cout << input[j];
            }
            cout << endl;
            
        }


    }


    void generateSubsets( )
    {
        
        vector<set<int>> subsets;
        set<int> sint; sint.insert(-1); // this is to represent a null value
        subsets.push_back( sint );
        
        vector<set<int>> n_subsets;


        array<int,3> arr_ = {1, 2, 3}; // { 1, 2, 3, 4, 5, 6, 7, 8 , 9 , 10 };
        
        
        for( int i=0; i < arr_.size(); i++ )
        {
         
            for( set<int>& ss : subsets )
            {
                set<int> newsub;
                copy( ss.begin(), ss.end(), inserter( newsub, newsub.begin() ) );
                n_subsets.push_back( newsub );
                
                set<int> newsub2;
                copy( ss.begin(), ss.end(), inserter( newsub2, newsub2.begin() ) );
                newsub2.insert( arr_[i] );
                
                n_subsets.push_back( newsub2 );
            }
        
            this->print( subsets );

            subsets.clear();
            copy( n_subsets.begin(), n_subsets.end(), inserter( subsets, subsets.begin() ) );
            this->print( n_subsets );
            
            n_subsets.clear();
            
        }
    
        this->print( subsets ); // printing done below
    }
    
    
    
    void  print( vector<set<int>>& subsets )
    {
        
        for( auto ss : subsets )
        {
            
            printf( "( " );
    
            for( auto val : ss )
            {
                if( val == -1 ) printf("");
                else
                {
                    printf( "%d, ", val );
                }
            }
            
            printf( " )\n" );
    
        }
        
    
    }

private:


};

int main()
{
    SubSets ss;

    vector<int> vec = {1, 2, 3};

    //ss.PrintAllSubSets(vec);
    ss.generateSubsets();

    return 0;
}