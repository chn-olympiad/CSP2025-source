#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[15][10005],c[15],cnt[10005];
long long ans;
struct ui{
	int u;
	int v;
	int w;
}di[1000005];
inline bool cmp1(ui aaa,ui bbb){
	return aaa.w<bbb.w;
}
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>di[i].u>>di[i].v>>di[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		sort(di+1,di+1+m,cmp1);
		ans=0;
		for(int i=1;i<=m;i++){
			if(cnt[di[i].u]==0||cnt[di[i].v]==0){
				cnt[di[i].u]=1;
				cnt[di[i].v]=1;
				ans+=(long long)di[i].w;
			}
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
}