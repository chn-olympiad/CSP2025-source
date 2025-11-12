#include <bits/stdc++.h>
using namespace std;

int m,n,k;
int wdf[10015][10015];
int cost[15];

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for (int i=1; i<=m; i++){
		int ui,vi,wi;
		cin>>ui>>vi>>wi;
		if (ui>vi)	wdf[ui][vi]=wi;
		else	wdf[vi][ui]=wi;
	}
	
	for (int i=1; i<=k; i++){
		cin>>cost[i];
		cin>>wdf[m+i][i];
		
	}
	
	return 0;
	
	
}