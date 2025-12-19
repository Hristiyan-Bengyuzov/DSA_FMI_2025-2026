// https://leetcode.com/problems/course-schedule-ii/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    enum State {
        UNIVISITED = 0,
        VISITING,
        VISITED
    };

    bool dfs(int curr, vector<vector<int>>& graph, vector<State>& visited, vector<int>& res) {
        visited[curr] = VISITING;

        for (int& next : graph[curr]) {
            if (!visited[next])
            {
                if (dfs(next, graph, visited, res))
                    return true;
            }
            else if (visited[next] == VISITING)
            {
                return true;
            }
        }

        visited[curr] = VISITED;
        res.push_back(curr);
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<State> visited(numCourses, UNIVISITED);
        vector<vector<int>> graph(numCourses);
        vector<int> res;

        for (auto& edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
        }

        for (size_t i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, graph, visited, res))
                    return {};
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};