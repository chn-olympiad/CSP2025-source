#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;

#define OPEN freopen("road.in","r",stdin),freopen("road.out","w",stdout);
int n,m,k,w,v,u,Map[N][N],lig[N],answ = INT_MAX;
bool check()
{
	for(int i = 1;i <= n;i++)
		if(!lig[i]) return 0;
	return 1;
}
int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	OPEN
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++) Map[i][j] = INT_MAX;
	for(int i = 1;i <= m;i++){
		cin >> u >> v >> w;
		Map[u][v] = w;
		Map[v][u] = w;
	}
	
	for(int i = 1;i <= n;i++){
		int ans = 0,minn = 32767,k = 0;
		memset(lig,0,sizeof(lig));
		lig[i] = 1;
		while(check()){
			for(int p = 1;p <= n;p++){
				for(int j = 1;j <= m;j++){
					if(Map[p][j] < minn){
						minn = Map[p][j];
						k = j;
					}
				}
				lig[k] = 1;
				ans += minn;
			}
		}
		answ = min(answ,ans);
		
	}
	cout << answ;
	return 0;
}
