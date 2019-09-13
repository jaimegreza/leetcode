#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>


using namespace std;

class VectorReverse
{
public:
    VectorReverse(){};

    void vectorReverse(vector<int> vec)
    {
        int n = vec.size();
        
            // Swap character starting from two
            // corners
            for (int i=0; i<n/2; i++)
            {
                int temp = vec[i];
                vec[i] = vec[n-i-1];
                vec[n-i-1] = temp;
            }

            for (auto i = vec.begin(); i != vec.end(); ++i)
               cout << *i << ' ';
    
               cout << endl;

            for (auto i: vec)
                cout << i << ' ';

                list<int> ll = { 1, 3, 5, 7, 9, 11, 13, 16, 21, 23, 26, 33, 36, 42, 44, 59 };
                vector<int> vec2 = { 2 ,3, 2, 2, 4, 2, 5, 2, 1 };
                deque<int> q = { 1, 2, 3, 4, 5, 6, 7, 8 , 9 , 10 };
                int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8 , 9 , 10 };
                array<int, 4> a1 = { 1,2,3,4 };
                array<int, sizeof(arr) / sizeof(int)> arr1 = { 1, 2, 3, 4, 5, 6, 7, 8 , 9 , 10 };
                
                std::cout << "array size: " << sizeof(arr)/sizeof(int) << endl;
            
                set<int> sett;
                map<int,int> mapp;
            
                unordered_set<int> settt;
                unordered_map<int, int> map;
                
                // process vec
                for (int i = 0; i < arr1.size(); i++)
                {
                    int key = arr1[i];
                    map[key] = i;
            //		sett.insert(key);
                }
                
                std::unordered_map<int, int>::iterator itr = map.begin();
                std::unordered_map<int, int>::const_iterator citr = map.cbegin();
            
                //std::map<int, int>::iterator itr = mapp.begin();
                //std::map<int, int>::const_iterator citr = mapp.cbegin();
                //std::map<int, int>::reverse_iterator ritr = mapp.rbegin();
                //std::map<int, int>::const_reverse_iterator critr = mapp.crbegin();
            
                while (citr != map.cend())
                {
            //		std::cout << *itr++ << endl;
                    std::cout << (*citr).first << " 2nd: "  << (*citr).second << endl;
                    citr++;
            
                }
                for ( int item : sett)
                {
            
                }
            
                for (std::pair<int,int> item : map)
                {
            
                    std::cout << item.first << " 2nd: " << item.second << endl;
            
                }
            
                //set<int>::iterator itr = sett.begin();
                //set<int>::const_iterator citr = sett.cbegin();
                //set<int>::reverse_iterator ritr = sett.rbegin();
                //set<int>::const_reverse_iterator critr = sett.crbegin();
            
                
                //std::array<int, arr1.size()>::iterator itr = arr1.begin();
                //std::array<int, arr1.size()>::const_iterator citr = arr1.cbegin();
                //std::array<int, arr1.size()>::reverse_iterator ritr = arr1.rbegin();
                //std::array<int, arr1.size()>::const_reverse_iterator critr = arr1.crbegin();
            
                //auto itr = std::begin(arr);
                //auto citr = std::cbegin(arr);
                //auto ritr = std::rbegin(arr);
                //auto critr = std::crbegin(arr);
            
            
                //vector<int>::iterator itr = vec.begin();
                //vector<int>::const_iterator citr = vec.cbegin();
                //vector<int>::reverse_iterator ritr = vec.rbegin();
                //vector<int>::const_reverse_iterator critr = vec.crbegin();
            
                
                //list<int>::iterator itr = ll.begin();
                //list<int>::const_iterator citr = ll.cbegin();
                //list<int>::reverse_iterator ritr = ll.rbegin();
                //list<int>::const_reverse_iterator critr = ll.crbegin();
            
                //deque<int>::iterator itr = q.begin();
                //deque<int>::const_iterator citr = q.cbegin();
                //deque<int>::reverse_iterator ritr = q.rbegin();
                //deque<int>::const_reverse_iterator critr = q.crbegin();
                
            
                //for (auto itr : arr)
                //{
                //	std::cout << itr++ << endl;
                //}
            
                //	for (auto itr : vec)
            //	while (itr != std::end(arr))
            //	while (citr != std::cend(arr))
            //	while (ritr != std::rend(arr))
            //	while (rcitr != std::crend(arr))
                //while (critr != std::crend(arr))
                //{
                //	std::cout << *critr++ << endl;
                //}
            



    }

    
};


int main()
{
    vector<int> vec1  = {1,2,3,4,5};

    VectorReverse vecReverse;

    vecReverse.vectorReverse(vec1);

    return 0;
}