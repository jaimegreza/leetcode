#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Event
{
    int start;
    int end;
    Event(int a, int b) : start(a), end(b){};
};

class Solution
{
    public:
    vector<Event> overlapped(vector<Event> events)
    {
        vector<Event> result;

        if (events.size() <= 1)
            return result;

        std::sort(events, [](Event ev1, Event ev2){ return ev1.start < ev2.start;} );

        result = events;

        return result;

    }

};

int main()
{
    Solution sol;
    vector<Event> input;
    vector<Event> results;

    Event ev1(3,7);
    Event ev2(2,3);
    Event ev3(6,9);

    input.push_back(ev1);
    input.push_back(ev2);
    input.push_back(ev3);

    for (Event e : input)
    {
        cout << e.start << " : " << e.end << endl;
    }

    results = sol.overlapped(input);
    
    for (Event e : results)
    {
        cout << e.start << " : " << e.end << endl;
    }

}