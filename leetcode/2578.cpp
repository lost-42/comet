#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int splitNum(int num) {
        priority_queue<int, vector<int>, greater<int>> pq{};
        while (num > 0) {
            pq.push(num % 10);
            num /= 10;
        }

        int n1 = 0, n2 = 0;
        while (!pq.empty()) {
            n1 = n1 * 10 + pq.top();
            pq.pop();

            if (!pq.empty()) {
                n2 = n2 * 10 + pq.top();
                pq.pop();
            }
        }

        return n1 + n2;
    }
};

int main() {
    Solution s{};
    cout << s.splitNum(4325) << endl;
    cout << s.splitNum(687) << endl;
    cout << s.splitNum(10000) << endl;
}
