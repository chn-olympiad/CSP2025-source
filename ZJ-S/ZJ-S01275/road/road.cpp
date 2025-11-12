#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct node{
	int u,v,c;
}e[N];
int n,m,k,a[1001][1001],q[1001][1001],c[100005];
long long ans=0,f[1001][1001];
bool flag[100005];
bool cmp(node x,node y){
	return x.c<y.c;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		e[i].u=x,e[i].v=y,e[i].c=z;
//		e[cnt].u=y,e[cnt].v=x,e[cnt].c=z;
	}
	bool ff=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i])ff=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=m;i++){
			if(flag[e[i].u]&&flag[e[i].v])continue;
			else{
				flag[e[i].u]=1;
				flag[e[i].v]=1;
				ans+=e[i].c;
			}
		}
		cout<<ans;
	}
	else if(ff){
		int cnt=m;
		for(int i=1;i<=m;i++){
			q[e[i].u][e[i].v]=q[e[i].u][e[i].v]=e[i].c;
			f[e[i].u][e[i].v]=f[e[i].u][e[i].v]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int l=1;l<=k;l++){
					if(f[i][j])q[i][j]=min(q[i][j],a[l][i]+a[l][j]);
					else q[i][j]=a[l][i]+a[l][j];
//					cout<<i<<" "<<j<<" "<<k<<" "<<a[l][i]<<" "<<a[l][j]<<" "<<q[i][j]<<endl;
				}	
			}
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt++;
				e[cnt].u=i,e[cnt].v=j,e[cnt].c=q[i][j];
//				cout<<i<<" "<<j<<" "<<e[cnt].c<<endl;
			}
		}
		sort(e+1,e+cnt+1,cmp);
		for(int i=1;i<=cnt;i++){
			if(flag[e[i].u]&&flag[e[i].v])continue;
			else{
				flag[e[i].u]=1;
				flag[e[i].v]=1;
				ans+=e[i].c;
			}
		}
		cout<<ans;
	}
	return 0;
}

