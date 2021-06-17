#include <iostream>
#include <vector>

namespace JIMMY
{
    template<class InputIterator, class UnaryPredicate>
    bool all_of (InputIterator first, InputIterator last, UnaryPredicate pred)
    {
        while (first!=last) {
            if (!pred(*first)) return false;
            ++first;
        }
        return true;
    }

    template<class InputIterator, class UnaryPredicate>
    bool any_of (InputIterator first, InputIterator last, UnaryPredicate pred)
    {
        while (first!=last) {
            if (pred(*first)) return true;
            ++first;
        }
        return false;
    }

    template<class InputIterator, class UnaryPredicate>
    bool none_of (InputIterator first, InputIterator last, UnaryPredicate pred)
    {
        while (first!=last) {
            if (pred(*first)) return false;
            ++first;
        }
        return true;
    }

    template<class InputIterator, class Function>
    Function for_each(InputIterator first, InputIterator last, Function fn)
    {
        while (first!=last) {
            fn (*first);
            ++first;
        }
        return fn;      // or, since C++11: return move(fn);
    }


    template<class InputIterator, class T>
    InputIterator find (InputIterator first, InputIterator last, const T& val)
    {
        while (first!=last) {
            if (*first==val) return first;
            ++first;
        }
        return last;
    }

    template<class InputIterator, class UnaryPredicate>
    InputIterator find_if (InputIterator first, InputIterator last, UnaryPredicate pred)
    {
        while (first!=last) {
        if (pred(*first)) return first;
            ++first;
        }
        return last;
    }
    
    template<class InputIterator, class UnaryPredicate>
    InputIterator find_if_not (InputIterator first, InputIterator last, UnaryPredicate pred)
    {
        while (first!=last) {
            if (!pred(*first)) return first;
            ++first;
        }
        return last;
    }

    template<class ForwardIterator1, class ForwardIterator2>
    ForwardIterator1 find_end ( ForwardIterator1 first1, ForwardIterator1 last1,
                                ForwardIterator2 first2, ForwardIterator2 last2)
    {
        if (first2==last2) return last1;  // specified in C++11

        ForwardIterator1 ret = last1;

        while (first1!=last1)
        {
            ForwardIterator1 it1 = first1;
            ForwardIterator2 it2 = first2;
            while (*it1==*it2) {    // or: while (pred(*it1,*it2)) for version (2)
                ++it1; ++it2;
                if (it2==last2) { ret=first1; break; }
                if (it1==last1) return ret;
            }
            ++first1;
        }
        return ret;
    }

    template<class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
    ForwardIterator1 find_end ( ForwardIterator1 first1, ForwardIterator1 last1,
                                ForwardIterator2 first2, ForwardIterator2 last2,
                                BinaryPredicate pred)
    {
        if (first2==last2) return last1;  // specified in C++11

        ForwardIterator1 ret = last1;

        while (first1!=last1)
        {
            ForwardIterator1 it1 = first1;
            ForwardIterator2 it2 = first2;
            while (pred(*it1,*it2)){
                ++it1; ++it2;
                if (it2==last2) { ret=first1; break; }
                if (it1==last1) return ret;
            }
            ++first1;
        }
        return ret;
    }


    template<class InputIterator, class ForwardIterator>
    InputIterator find_first_of (   InputIterator first1, InputIterator last1,
                                    ForwardIterator first2, ForwardIterator last2)
    {
        while (first1!=last1) {
            for (ForwardIterator it=first2; it!=last2; ++it) {
                if (*it==*first1)          // or: if (pred(*it,*first)) for version (2)
                    return first1;
            }
            ++first1;
        }
        return last1;
    }
    
    template<class InputIterator, class ForwardIterator, class BinaryPredicate>
    InputIterator find_first_of (   InputIterator first1, InputIterator last1,
                                    ForwardIterator first2, ForwardIterator last2,
                                    BinaryPredicate pred)
    {
        while (first1!=last1) {
            for (ForwardIterator it=first2; it!=last2; ++it) {
                if (pred(*it,*first1))
                    return first1;
            }
            ++first1;
        }
        return last1;
    }


    template <class ForwardIterator>
    ForwardIterator adjacent_find (ForwardIterator first, ForwardIterator last)
    {
        if (first != last)
        {
            ForwardIterator next=first; ++next;
            while (next != last) {
                if (*first == *next)     // or: if (pred(*first,*next)), for version (2)
                    return first;
                ++first; ++next;
            }
        }
        return last;
    }

    template <class ForwardIterator, class BinaryPredicate>
    ForwardIterator adjacent_find ( ForwardIterator first, ForwardIterator last,
                                    BinaryPredicate pred)
    {
        if (first != last)
        {
            ForwardIterator next=first; ++next;
            while (next != last) {
                if (pred(*first,*next))
                    return first;
                ++first; ++next;
            }
        }
        return last;
    }

    template <class InputIterator, class T>
    typename std::iterator_traits<InputIterator>::difference_type
        count (InputIterator first, InputIterator last, const T& val)
    {
        typename std::iterator_traits<InputIterator>::difference_type ret = 0;
        while (first!=last) {
            if (*first == val) ++ret;
                ++first;
        }
        return ret;
    }

    template <class InputIterator, class UnaryPredicate>
    typename std::iterator_traits<InputIterator>::difference_type
        count_if (InputIterator first, InputIterator last, UnaryPredicate pred)
    {
        typename std::iterator_traits<InputIterator>::difference_type ret = 0;
        while (first!=last) {
            if (pred(*first)) ++ret;
                ++first;
        }
        return ret;
    }

    template <class InputIterator1, class InputIterator2>
    std::pair<InputIterator1, InputIterator2>
        mismatch (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
    {
        while ( (first1!=last1) && (*first1==*first2) )  // or: pred(*first1,*first2), for version 2
        { ++first1; ++first2; }
        
        return std::make_pair(first1,first2);
    }

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    std::pair<InputIterator1, InputIterator2>
        mismatch (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
    {
        while ( pred(*first1,*first2) )
        { ++first1; ++first2; }        
        return std::make_pair(first1,first2);
    }

    template <class InputIterator1, class InputIterator2>
    std::pair<InputIterator1, InputIterator2>
        zip_find (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
    {
        while ( (first1!=last1) && (*first1==*first2) )  // or: pred(*first1,*first2), for version 2
        { ++first1; ++first2; }
        
        return std::make_pair(first1,first2);
    }

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    std::pair<InputIterator1, InputIterator2>
        zip_find (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
    {
        while ( (first1!=last1) && pred(*first1,*first2) )
        { ++first1; ++first2; }        
        return std::make_pair(first1,first2);
    }


    template <class InputIterator1, class InputIterator2>
    bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
    {
        while (first1!=last1) {
            if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
                return false;
            ++first1; ++first2;
        }
        return true;
    }

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
      bool equal (InputIterator1 first1, InputIterator1 last1,
              InputIterator2 first2, BinaryPredicate pred)
    {
        while (first1!=last1) {
            if (!pred(*first1,*first2))
                return false;
            ++first1; ++first2;
        }
        return true;
    }


    template <class InputIterator1, class InputIterator2>
        bool is_permutation (InputIterator1 first1, InputIterator1 last1,
                       InputIterator2 first2)
    {
        std::tie (first1,first2) = std::mismatch (first1,last1,first2);
        if (first1==last1) return true;
        InputIterator2 last2 = first2; std::advance (last2,std::distance(first1,last1));
        for (InputIterator1 it1=first1; it1!=last1; ++it1) {
            if (std::find(first1,it1,*it1)==it1) {
                auto n = std::count (first2,last2,*it1);
                if (n==0 || std::count (it1,last1,*it1)!=n) return false;
            }
        }
        return true;
    }

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
        bool is_permutation (InputIterator1 first1, InputIterator1 last1,
                       InputIterator2 first2, BinaryPredicate pred)
    {
        std::tie (first1,first2) = std::mismatch (first1,last1,first2,pred);
        if (first1==last1) return true;
        InputIterator2 last2 = first2; std::advance (last2,std::distance(first1,last1));
        for (InputIterator1 it1=first1; it1!=last1; ++it1) {
            if (std::find(first1,it1,*it1)==it1) {
                auto n = std::count (first2,last2,*it1);
                if (n==0 || std::count (it1,last1,*it1)!=n) return false;
            }
        }
        return true;
    }


    template<class ForwardIterator1, class ForwardIterator2>
    ForwardIterator1 search ( ForwardIterator1 first1, ForwardIterator1 last1,
                            ForwardIterator2 first2, ForwardIterator2 last2)
    {
        if (first2==last2) return first1;  // specified in C++11
  
        while (first1!=last1)
        {
            ForwardIterator1 it1 = first1;
            ForwardIterator2 it2 = first2;
            while (*it1==*it2) {    // or: while (pred(*it1,*it2)) for version 2
                if (it2==last2) return first1;
                if (it1==last1) return last1;
                ++it1; ++it2;
            }
            ++first1;
        }
        return last1;
    }

    template<class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
    ForwardIterator1 search ( ForwardIterator1 first1, ForwardIterator1 last1,
                            ForwardIterator2 first2, ForwardIterator2 last2,
                            BinaryPredicate pred)
    {
        if (first2==last2) return first1;  // specified in C++11
  
        while (first1!=last1)
        {
            ForwardIterator1 it1 = first1;
            ForwardIterator2 it2 = first2;
            while (pred(*it1,*it2)) {
                if (it2==last2) return first1;
                if (it1==last1) return last1;
                ++it1; ++it2;
            }
            ++first1;
        }
        return last1;
    }


    template<class ForwardIterator, class Size, class T>
    ForwardIterator search_n (ForwardIterator first, ForwardIterator last,
                            Size count, const T& val)
    {
        ForwardIterator it, limit;
        Size i;

        limit=first; std::advance(limit,std::distance(first,last)-count);

        while (first!=limit)
        {
            it = first; i=0;
            while (*it==val)       // or: while (pred(*it,val)) for the pred version
            { ++it; if (++i==count) return first; }
            ++first;
        }
        return last;
    }

    template<class ForwardIterator, class Size, class T, class BinaryPredicate>
    ForwardIterator search_n (ForwardIterator first, ForwardIterator last,
                            Size count, const T& val, BinaryPredicate pred)
    {
        ForwardIterator it, limit;
        Size i;

        limit=first; std::advance(limit,std::distance(first,last)-count);

        while (first!=limit)
        {
            it = first; i=0;
            while (pred(*it,val))
            { ++it; if (++i==count) return first; }
            ++first;
        }
        return last;
    }


 
    template <class BidirectionalIterator>
    void reverse (BidirectionalIterator first, BidirectionalIterator last)
    {
        while ((first!=last)&&(first!=--last)) {
            std::iter_swap (first,last);
            ++first;
        }
    }


    template <class ForwardIterator>
    void rotate (ForwardIterator first, ForwardIterator middle,
               ForwardIterator last)
    {
        ForwardIterator next = middle;
        while (first!=next)
        {
            std::swap (*first++,*next++);
            if (next==last) next=middle;
            else if (first==middle) middle=next;
        }
    }

    template <class InputIterator, class UnaryPredicate>
    bool is_partitioned (InputIterator first, InputIterator last, UnaryPredicate pred)
    {
        while (first!=last && pred(*first)) {
            ++first;
        }
        while (first!=last) {
            if (pred(*first)) return false;
            ++first;
        }
        return true;
    }


    template <class BidirectionalIterator, class UnaryPredicate>
    BidirectionalIterator partition (BidirectionalIterator first,
                                   BidirectionalIterator last, UnaryPredicate pred)
    {
        while (first!=last) {
            while (pred(*first)) {
                ++first;
                if (first==last) return first;
            }
    
            do {
                --last;
                if (first==last) return first;
            } while (!pred(*last));
    
            swap (*first,*last);
            ++first;
        }
        return first;
    }

    template <class ForwardIterator, class UnaryPredicate>
    ForwardIterator partition_point (ForwardIterator first, ForwardIterator last,
                                   UnaryPredicate pred)
    {
        auto n = distance(first,last);
        while (n>0)
        {
            ForwardIterator it = first;
            auto step = n/2;
            std::advance (it,step);
            if (pred(*it)) { first=++it; n-=step+1; }
                else n=step;
        }
        return first;
    }


    template <class InputIterator, class T>
    T accumulate (InputIterator first, InputIterator last, T init)
    {
        while (first!=last) {
            init = init + *first;  // or: init=binary_op(init,*first) for the binary_op version
            ++first;
        }
        return init;
    }

    template <class InputIterator, class T, class BinaryOperation>
    T accumulate (InputIterator first, InputIterator last, T init, BinaryOperation binary_op)
    {
        while (first!=last) {
            init=binary_op(init,*first);
            ++first;
        }
        return init;
    }

    template <class InputIterator, class OutputIterator>
    OutputIterator adjacent_difference (InputIterator first, InputIterator last,
                                       OutputIterator result)
    {
        if (first!=last) {
            typename std::iterator_traits<InputIterator>::value_type val,prev;
            *result = prev = *first;
    
            while (++first!=last) {
                val = *first;
                *++result = val - prev;  // or: *++result = binary_op(val,prev)
                prev = val;
            }
            ++result;
        }
        return result;
    }

    template <class InputIterator, class OutputIterator, class BinaryOperation>
    OutputIterator adjacent_difference (InputIterator first, InputIterator last,
                                       OutputIterator result, BinaryOperation binary_op)
    {
        if (first!=last) {
            typename std::iterator_traits<InputIterator>::value_type val,prev;
            *result = prev = *first;
    
            while (++first!=last) {
                val = *first;
                *++result = binary_op(val,prev);
                prev = val;
            }
            ++result;
        }
        return result;
    }
     

    template <class InputIterator1, class InputIterator2, class T>
    T inner_product (InputIterator1 first1, InputIterator1 last1,
                    InputIterator2 first2, T init)
    {
        while (first1!=last1) {
            init = init + (*first1)*(*first2);
               // or: init = binary_op1 (init, binary_op2(*first1,*first2));
            ++first1; ++first2;
        }
        return init;
    }

    template <class InputIterator1, class InputIterator2, class T, class BinaryOp>
    T inner_product (InputIterator1 first1, InputIterator1 last1,
                    InputIterator2 first2, T init, BinaryOp binary_op1, BinaryOp binary_op2)
    {
        while (first1!=last1) {
            init = binary_op1 (init, binary_op2(*first1,*first2));
            ++first1; ++first2;
        }
        return init;
    }
    template <class InputIterator, class OutputIterator>
    OutputIterator partial_sum (InputIterator first, InputIterator last,
                               OutputIterator result)
    {
        if (first!=last) {
            typename std::iterator_traits<InputIterator>::value_type val = *first;
            *result = val;
            while (++first!=last) {
                val = val + *first;   // or: val = binary_op(val,*first)
                *++result = val;
            }
            ++result;
        }
        return result;
    }

    template <class InputIterator, class OutputIterator, class BinaryOperation>
    OutputIterator partial_sum (InputIterator first, InputIterator last,
                               OutputIterator result, BinaryOperation binary_op)
    {
        if (first!=last) {
            typename std::iterator_traits<InputIterator>::value_type val = *first;
            *result = val;
            while (++first!=last) {
                val = binary_op(val,*first)
                *++result = val;
            }
            ++result;
        }
        return result;
    }

    template <class InputIterator1, class InputIterator2, class T, class BinaryOperation1, class BinaryOperation2>
    T inner_product (InputIterator1 first1, InputIterator1 last1,
                    InputIterator2 first2, T init, 
                    BinaryOperation1 binary_op1,
                    BinaryOperation2 binary_op2)
    {
        while (first1!=last1) {
            init = binary_op1 (init, binary_op2(*first1,*first2));
            ++first1; ++first2;
        }
        return init;
    }
    


    template <class InputIterator, class OutputIterator, class UnaryOperator>
    OutputIterator transform (InputIterator first1, InputIterator last1,
                            OutputIterator result, UnaryOperator op)
    {
        while (first1 != last1) {
            *result = op(*first1);  // or: *result=binary_op(*first1,*first2++);
            ++result; ++first1;
        }
        return result;
    }

    template <class InputIterator1, class InputIterator2, class OutputIterator, class BinaryOperation>
    OutputIterator transform (InputIterator1 first1, InputIterator1 last1,
                            InputIterator2 first2, OutputIterator result,
                            BinaryOperation binary_op)
    {
        while (first1 != last1) {
            *result=binary_op(*first1,*first2++);
            ++result; ++first1;
        }
        return result;
    }


    template <class InputIterator1, class InputIterator2, class T, class BinaryOp1, class BinaryOp2>
    T   transform_reduce(   InputIterator1 first1, InputIterator1 last1,
                            InputIterator2 first2, T init,  BinaryOp1 b1, BinaryOp2 b2)
    {
        for (; first1 != last1; ++first1, (void) ++first2)
            init = b1(init, b2(*first1, *first2));
        return init;
    }

    template <class InputIterator1, class InputIterator2, class T>
    T   transform_reduce(   InputIterator1 first1, InputIterator1 last1,
                            InputIterator2 first2, T init)
    {
        return transform_reduce(first1, last1, first2, std::move(init),
                                   std::plus<>(), std::multiplies<>());
    }


    template <class InputIterator, class T, class BinaryOp>
    T   reduce(InputIterator first, InputIterator last, T init, BinaryOp b)
    {
        for (; first != last; ++first)
            init = b(init, *first);
        return init;
    }

    template <class InputIterator, class T>
    T   reduce(InputIterator first, InputIterator last, T init)
    {
        return reduce(first, last, init, std::plus<>());
    }

    template <class InputIterator, class OutputIterator, class T, class BinaryOp>
    OutputIterator inclusive_scan(  InputIterator first, InputIterator last,
                                    OutputIterator result, BinaryOp b,  T init)
    {
        for (; first != last; ++first, (void) ++result) {
            init = b(init, *first);
            *result = init;
        }
        return result;
    }

    template <class InputIterator, class OutputIterator, class BinaryOp>
    OutputIterator inclusive_scan(  InputIterator first, InputIterator last,
                                    OutputIterator result, BinaryOp b)
    {
        if (first != last) {
            typename std::iterator_traits<InputIterator>::value_type init = *first;
            *result++ = init;
            if (++first != last)
                return inclusive_scan(first, last, result, b, init);
            }

        return result;
    }

    template <class InputIterator, class OutputIterator>
    OutputIterator inclusive_scan(  InputIterator first, InputIterator last,
                                    OutputIterator result)
    {
        return inclusive_scan(first, last, result, std::plus<>());
    }


    template <class InputIterator, class OutputIterator, class T, class BinaryOp>
    OutputIterator exclusive_scan(  InputIterator first, InputIterator last,
                                    OutputIterator result, T init, BinaryOp b)
    {
        if (first != last)
        {
            T saved = init;
            do
            {
                init = b(init, *first);
                *result = saved;
                saved = init;
                ++result;
            } while (++first != last);
        }
        return result;
    }

    template <class InputIterator, class OutputIterator, class T>
    OutputIterator  exclusive_scan( InputIterator first, InputIterator last,
                                    OutputIterator result, T init)
    {
        return exclusive_scan(first, last, result, init, std::plus<>());
    }


    template <  class InputIterator, class OutputIterator, class T,
                class BinaryOp, class UnaryOp>
    OutputIterator  transform_exclusive_scan(   InputIterator first, InputIterator last,
                                                OutputIterator result, T init,
                                                BinaryOp b, UnaryOp u)
    {
        if (first != last)
        {
            T saved = init;
            do
            {
                init = b(init, u(*first));
                *result = saved;
                saved = init;
                ++result;
            } while (++first != last);
        }
        return result;
    }

    template <class InputIterator, class OutputIterator, class T, class BinaryOp, class UnaryOp>
    OutputIterator transform_inclusive_scan(    InputIterator first, InputIterator last,
                                                OutputIterator result, BinaryOp b, UnaryOp u, T init)
    {
        for (; first != last; ++first, (void) ++result) {
            init = b(init, u(*first));
            *result = init;
        }

        return result;
    }

    template <class InputIterator, class OutputIterator, class BinaryOp, class UnaryOp>
    OutputIterator transform_inclusive_scan(InputIterator first, InputIterator last,
                               OutputIterator result, BinaryOp b, UnaryOp u)
    {
        if (first != last) {
            typename std::iterator_traits<InputIterator>::value_type init = u(*first);
            *result++ = init;
            if (++first != last)
                return transform_inclusive_scan(first, last, result, b, u, init);
        }

        return result;
    }

    template<typename BidirectionalIterator>
    void sort(BidirectionalIterator first, BidirectionalIterator last)
    {
        while (first != last)
        {
            BidirectionalIterator it = first;
            while (it != last)
            {
                if (*it < *first)
                {
                   std::iter_swap(it,first);
                }
                it++;
            }
            first++;
        }
    }



// pivot location is one less than counter index
    int partitionQuickSort(std::vector<int> &input, int low ,int high)
    {
        
        int i = high+1;

        for (int j=high;j > low;j--)
        {
            if (input[j] >= input[low])
            {
                i--;
                int temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }
 
        // swap pivot
        int temp = input[i-1];
        input[i-1] = input[low];
        input[low] = temp;
 
        return i-1;
    } 



    void quickSort(std::vector<int> &input, int low ,int high)
    {
        if (low < high)
        {
            int p = partitionQuickSort(input,low, high);

            quickSort(input, low, p-1);
            quickSort(input, p+1, high);
            
        }        
    }
    
    /** divide and conquer ***/
/*** recursive ***/
/** lobbing stuff over the fence **/

    void quickSort(std::vector<int> &input)
    {

        if (input.size() <= 1)
            return;

        quickSort(input, 0 ,input.size()-1);
    

    }


}