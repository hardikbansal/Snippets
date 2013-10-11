#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>

#define INF 10000000
#define PB push_back

using namespace std;
const int MAX = 10001;
typedef pair< int, int > pii;
vector< pii > G[MAX], R[MAX];
int fromS[MAX];
bool flagG[MAX];


void dijkstra(int s, vector< pii > *graph, int *dist, bool *flag) {
	priority_queue< pii, vector< pii >, greater< pii > > Q;
	Q.push(pii(0,s));
	int u, v, w, i, sz;
	dist[s] = 0;
	while(!Q.empty()) {
		u = Q.top().second;
		Q.pop();
		if(flag[u]) continue;
		sz = graph[u].size();
		for(i = 0; i < sz; i++) {
			v = graph[u][i].second;
			w = graph[u][i].first;
			if(!flag[v] && dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				Q.push(pii(dist[v], v));
			}
		}
		flag[u] = true;
	}
}

int main() {
	int t, n, e, u, v, w, i, k, s, f, best;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &e);
		for(i = 1; i <= n; i++) {
			G[i].clear();
			fromS[i] = INF;
			flagG[i] = false;
		}
		scanf("%d%d%d", &k, &s, &f);
		for(i = 0; i < e; i++) {
			scanf("%d%d%d", &u, &v, &w);
			G[u].PB(pii(w,v));
		}
		dijkstra(s, G, fromS, flagG);
	}
	return 0;
}
