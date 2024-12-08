#include <bits/stdc++.h>
using namespace std;

vector<string> grid;

vector<pair<int, int>> getAntiNodes(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int firstNode_x = x2 + dx, firstNode_y = y2 + dy;
    int secondNode_x = x1 - dx, secondNode_y = y1 - dy;
    vector<pair<int, int>> antiNodes;
    if(firstNode_x >=0 and firstNode_x < grid.size() and firstNode_y >=0 and firstNode_y < grid[0].size() )
    {
        antiNodes.push_back({firstNode_x, firstNode_y});
    }
    if(secondNode_x >=0 and secondNode_x < grid.size() and secondNode_y >=0 and secondNode_y < grid[0].size() )
    {
        antiNodes.push_back({secondNode_x, secondNode_y});
    }
    return antiNodes;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    vector<string> input;
    string s;
    while (getline(cin, s))
    {
        input.push_back(s);
    }
    grid = input;
    map<char, vector<pair<int, int>>> nodes;
    for (int i = 0;i<input.size();i++)
    {
        for (int j = 0;j<input[i].size();j++)
        {
            if(input[i][j] != '.')
            {
                char ch = input[i][j];
                nodes[ch].push_back({i, j});
            }
        }
    }
    set<pair<char, char>> antiNodePoints;
    for(auto node : nodes)
    {
        vector<pair<int, int>> nodePoints = node.second;
        for(int i = 0;i<nodePoints.size();i++)
        {
            for(int j = i+1;j<nodePoints.size();j++)
            {
                int x1 = nodePoints[i].first, y1 = nodePoints[i].second;
                int x2 = nodePoints[j].first, y2 = nodePoints[j].second;
                vector<pair<int, int>> antiNodes = getAntiNodes(x1, y1, x2, y2);
                for(auto antiNode : antiNodes)
                {
                    antiNodePoints.insert(antiNode);
                }
            }
        }
    }
    cout<<antiNodePoints.size()<<endl;
}