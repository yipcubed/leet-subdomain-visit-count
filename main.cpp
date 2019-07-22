#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/subdomain-visit-count/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<string> subdomainVisits(vector<string> &cpdomains) {
        unordered_map<string, int> d;
        for (auto &s: cpdomains) {
            istringstream iss(s);
            int visits;
            iss >> visits;
            string domain;
            iss >> domain;
            unsigned long it = 0;
            do {
                string sub = domain.substr(it, domain.length() - it);
                d[sub] += visits;
                it = domain.find('.', it);
            } while (it++ != string::npos);
        }
        vector<string> results(d.size());
        int index = 0;
        for (auto &p: d) {
            results[index++] = to_string(p.second) + " " + p.first;
        }
        return results;
    }
};

void test1() {
    vector<string> v1{"9001 discuss.leetcode.com"};


    cout << "[\"9001 discuss.leetcode.com\", \"9001 leetcode.com\", \"9001 com\"] ?\n"
         << Solution().subdomainVisits(v1) << endl;

    vector<string> v2{"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};

    cout << "[\"901 mail.com\",\"50 yahoo.com\",\"900 google.mail.com\","
            "\"5 wiki.org\",\"5 org\",\"1 intel.mail.com\",\"951 com\"] ?\n "
         << Solution().subdomainVisits(v2) << endl;
}

void test2() {

}

void test3() {

}