#include<bits/stdc++.h>
using namespace std;

int n,m,k,cnt1,cnt2;
struct str{
	int u,v,w;
}money[1000010];
int a[1000010],b[1000010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		a[u]=(a[u]==0?w:min(a[u],w));
		b[v]=(b[v]==0?w:min(b[v],w));
		
	}
	for(int i=1;i<=m;i++){
		if(i>1&&b[i]!=INT_MAX) cnt1+=b[i];
		if(i<m&&a[i]!=INT_MAX) cnt2+=a[i];
	}
	cout << min(cnt1,cnt2);	
	
	return 0;
}
