#include <bits/stdc++.h>
using namespace std;
int n,m,k,fa[10005],ans;
int q[10005][10005];
bool v[10005];
int fd(int a){
	if(a==fa[a])return a;
	fa[a]=fd(fa[a]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)fa[i]=i;
	memset(q,-1,sizeof(q));
	for(int i=1;i<=m;i++){
		int a,b,v;
		cin>>a>>b>>v;
		q[a][b]=v;
		q[b][a]=v;
	}
	int ov=0;
	v[1]=1;
	while(ov<n-1){
		int mit,mif,mi=1e9;
		for(int i=1;i<=n;i++){
			if(v[i]){
				for(int j=1;j<=n;j++){
					if(q[i][j]!=-1&&!v[j]&&mi>q[i][j]&&fd(i)!=fd(j)){
						mit=j;
						mif=i;
						mi=q[i][j];
					}
				}
			}
		}
		fa[mif]=fd(mit);
		v[mit]=1;
		ans+=mi;
		ov++;
	}
	while(k--){
		int a;
		cin>>a;
		for(int i=0,j=0;i<a;i++){
			cin>>j;
		}
		if(a==0){
			cout<<0;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}
