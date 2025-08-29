#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
		vector<int> dist(n + 1, INT_MAX);
		vector<int> visited(n + 1, false);
		priority_queue< pair<int,int>, vector< pair<int,int> >, greater<pair<int,int>> > pq;

		// create the adjency array + each cost
		for (int i = 0; i < times.size(); ++i)
		{
			adj[times[i][0]].push_back({times[i][1], times[i][2]});
		}

		// dijkstra

		dist[k] = 0;
		pq.emplace(0, k);
		while (!pq.empty())
		{
			int curr = pq.top().second;
			pq.pop();
			if (visited[curr])
				continue;
			visited[curr] = true;
			for (int i = 0; i < adj[curr].size(); ++i)
			{
				if (dist[adj[curr][i].first] > dist[curr] + adj[curr][i].second)
					dist[adj[curr][i].first] = dist[curr] + adj[curr][i].second;
				pq.emplace(dist[adj[curr][i].first], adj[curr][i].first);
			}
		}

		int max = 0;
		for (int i = 1; i < dist.size(); ++i)
		{
			if (dist[i] == INT_MAX)
				return (-1);
			if (dist[i] > max)
				max = dist[i];
		}
		return (max);
    }
};