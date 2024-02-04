#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class TopVotedCandidate {
public:
    unordered_map<int, int> m;
    vector<int> times;
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        int n = persons.size(), lead = -1;
        this->times = times;
        unordered_map<int, int> count;
        for (int i = 0; i < n; ++i) {
            lead = ++count[persons[i]] >= count[lead] ? persons[i] : lead;
            m[times[i]] = lead;
        }
    }

    int q(int t) {
        return m[*--upper_bound(times.begin(), times.end(), t)];
    }
};

int main() {
    vector<int> persons = {0,1,1,0,0,1,0};
    vector<int> times = {0,5,10,15,20,25,30};
    TopVotedCandidate obj(persons, times);
    cout << obj.q(3) << endl; // 0
    cout << obj.q(12) << endl; // 1
    cout << obj.q(25) << endl; // 1
    cout << obj.q(15) << endl; // 0
    return 0;
}
