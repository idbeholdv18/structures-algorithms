#pragma once

#include <vector>
#include <queue>
#include <limits>

using namespace std;

namespace dijkstra {
    struct Edge
    {
        int to;
        int weigth;
    };
    
    vector<int> dijkstra(int start, const vector<vector<Edge>>& graph) {
        int n = graph.size();

        vector<int> dist(n, numeric_limits<int>::max());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [current_cost, u] = pq.top();
            pq.pop();

            if (current_cost > dist[u]) continue;

            for (const Edge& edge : graph[u]) {
                int v = edge.to;
                int weight = edge.weigth;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
}

