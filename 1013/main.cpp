#include<cstdio>
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

// last test point TLE.
const int maxn = 1010;
const int INF = 0x7fffffff;
int G[maxn][maxn];
bool vis[maxn] = { false };
int Point;
int n, m, k;

void dfs(int v) {
	if (v == Point)
		return;
	vis[v] = true;
	for (int i = 1; i <= n; ++i) {
		if (vis[i] == false && G[v][i] != INF)
			dfs(i);
	}
}

int main() {
    freopen("input1013.txt", "r", stdin);
	fill(G[0], G[0] + maxn*maxn, INF);
	int block;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; ++i) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		G[v1][v2] = 1;
		G[v2][v1] = 1;
	}

	for (int i = 0; i < k; ++i) {
		scanf("%d", &Point);
		fill(vis, vis + maxn, false);
		block = 0;
		for (int j = 1; j <= n; ++j) {
			if (vis[j] == false && j != Point) {
				block++;
				dfs(j);
			}
		}
		printf("%d\n", block-1);
	}
}
