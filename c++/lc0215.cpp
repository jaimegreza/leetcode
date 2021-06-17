#include <iostream>
#include <vector>

using namespace std;

class MinStack {


private:
    vector<int> heap;
    int size;

   /** initialize your data structure here. */
    // root = i = 1
    // parent = i/2
    // left = 2i
    // right 2i+1
    // the key of a node is < = key of its children

    void min_heapify(int idx){

        if (idx <= 0)
            return;

        if (idx > size)
            return;

        int par = heap[idx];

        // exchange with the smaller child
        bool useLeft = true;
        bool useRight = true;
        
        if (idx*2 > size)
            useLeft = false;

       if (idx*2+1 > size)
            useRight = false;

        if (!useRight && !useLeft)
            return;

        if (useLeft && useRight)
        {   
            int left = heap[idx*2];
            int right = heap[idx*2+1];  

            bool isLeftSmaller = (left < right);

            if (isLeftSmaller)
            {
                if (par > heap[idx*2])
                {
                    int temp = heap[idx];
                    heap[idx] = heap[idx*2];
                    heap[idx*2] = temp;
                    min_heapify(idx*2);
                }
            }
            else
            {
                if (par > heap[idx*2+1])
                {
                    int temp = heap[idx];
                    heap[idx] = heap[idx*2+1];
                    heap[idx*2+1] = temp;
                    min_heapify(idx*2+1);
                }
            }
        }
        else if (useLeft)
        {
            if (par > heap[idx*2])
            {
                int temp = heap[idx];
                heap[idx] = heap[idx*2];
                heap[idx*2] = temp;
                min_heapify(idx*2);
            }
        }
        else if (useRight)
        {
            if (par > heap[idx*2+1])
            {
                int temp = heap[idx];
                heap[idx] = heap[idx*2+1];
                heap[idx*2+1] = temp;
                min_heapify(idx*2+1);
            }            
        }

    }
   /** initialize your data structure here. */
    // root = i = 1
    // parent = i/2
    // left = 2i
    // right 2i+1
    // the key of a node is < = key of its children

    // Function to heapify ith node in a Heap 
    // of size n following a Bottom-up approach 
    void heapify(int idx) 
    { 
  
        int par = idx /2;
        if (par > 1) { 
            // For Min-Heap 
            // If current node is less than its parent 
            // Swap both of them and call heapify again 
            // for the parent 
            if (heap[idx] < heap[par]) 
            { 
                std::swap(heap[idx], heap[par]); 
  
                // Recursively heapify the parent node 
                heapify(par); 
            } 
        }

    }

    void insert(int x){

        if (size+1 == heap.size()+1)
            heap.resize(heap.size()*2);


        size++;
        int idx = size;
        heap[size] = x;
        heapify(idx);
/*            if (heap[par] > (heap[idx]))
            {
                int temp = heap[par];
                heap[par] = heap[idx];
                heap[idx] = temp;
                idx = idx/2;
            }
            else
                break;
        }*/
            
    }

    void extract_min(){
        int min = heap[1];

        heap[1] = heap[size];
        size--;

        min_heapify(1);
    };

public:
    /** initialize your data structure here. */
    // root = i = 1
    // parent = i/2
    // left = 2i
    // right 2i+1
    // the key of a node is < = key of its children

    MinStack() : heap(10), size(0) {
        
    }
    
    void push(int x) {
        insert(x);
    }
    
    void pop() {
        extract_min();
    }
    
    int top() {
        if (size > 0)
            return heap[1];

        return INT_MIN;
    }
    
    int getMin() {
        if (size > 0)
            return heap[1];
        return INT_MIN;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        MinStack heap;

        for (int i = 0; i < nums.size();i++)
        {
            heap.push(nums[i]);
        }

        int kth = nums.size() - k +1;
        while (kth > 1)
        {
            cout << "heap: " << heap.top() << endl;
            heap.pop();
            kth--;
        }

        return heap.top();
    }
};


int main()
{
    Solution sol;
    vector<int> inp = {3,2,1,5,6,4};
    cout << sol.findKthLargest(inp,2) << endl;
    
    inp = {3,2,3,1,2,4,5,5,6};
    cout << sol.findKthLargest(inp,4) << endl;

    inp = {3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
    cout << sol.findKthLargest(inp,2) << endl;

}