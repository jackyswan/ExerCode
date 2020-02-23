#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxDist = 0;
    int num = 0;
    void dfs(vector< vector<int> >& edges, int next, int step, vector<int>& map) {
        if (step > maxDist) {
            return;
        }
        int i = 0;
        cout << next << " dfs" << endl;
        if (map[next]) {
            return;
        }
        map[next] = 1;
        cout << next << " dfs2" << endl;
        num ++;
        cout << edges[i][0] << " dfs3" << endl;
        for (i = 0; i < 4; i++) {
            if (edges[i][0] == next) {
                dfs(edges, edges[i][1], step + edges[i][2], map);
            }
        }
        return;
    }
    int findTheCity(int n, vector< vector<int> >& edges, int distanceThreshold) {
        vector<int> map(n, 0);
        int ret = 0;
        
        maxDist = distanceThreshold;
        for (int i = 0; i < n; i++) {
            dfs(edges, i, 0, map);
            for (auto s : map) {
                s = 0;
            }
            if ((ret != 0 && num < ret) || (ret == 0)) {
                ret = num;
            }
            cout << i << "findTheCity" << endl;
            num = 0;
        }
        return ret;
    }
};

int main(void) {
    int ret;
    Solution solution;
    vector< vector<int> > edges[4][3] = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    ret = solution.findTheCity(4, edges, 4);
    cout << ret << endl;
}