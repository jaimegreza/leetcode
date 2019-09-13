#include <iostream>

using namespace std;

class T
{
public:
    int n1(int);
    int n2(int);
    int n3(int);
    
};

class U
{
public:
    int n1(int);
    int n2(int);
    int n3(int);
    
};

class Signal
{
public: 
    typedef int (T::*Method)(int);
    void connect(T *, Method);
    int operator()(int);
private: 
    T *object  = nullptr;
    Method method = nullptr;
};

int T::n1(int x)
{
    cout << __func__ <<  x << " " ;
    return x + 1;
}

int T::n2(int x)
{
    cout << __func__ <<  x << " " ;
    return x + 2;
}

int T::n3(int x)
{
    cout << __func__ <<  x << " " ;
    return x + 3;
}

void Signal::connect(T *o , Method m)
{
    object = o;
    method = m;

}

int Signal::operator()(int x)
{
    if (object && method)
     return (object->*method)(x);
    else
        return int();
}

int main()
{
    T t;
    Signal s;
    s.connect(&t, &T::n1);
    cout << s(10) << endl;
    s.connect(&t, &T::n2);
    cout << s(10) << endl;
    s.connect(&t, &T::n3);
    cout << s(10) << endl;

    return 0;
}