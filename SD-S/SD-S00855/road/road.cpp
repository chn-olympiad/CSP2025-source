#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c[15][1003],l;
int a[1003][1003],ans;
int f[1003];
struct st{
	int u,v;
	int w;
}b[1000005];
bool cmp(st a,st b){
	return a.w<b.w;
}
int find(int x){
	if(f[x]==x)return x;
	else return f[x]=find(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	memset(a,0x3f,sizeof(a));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=min(a[x][y],z);
		a[y][x]=min(a[y][x],z);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			for(int p=1;p<=k;p++){
				a[i][j]=min(a[i][j],(c[p][i]+c[p][j]+c[p][0]*1ll));
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			b[++l]={i,j,a[i][j]};
		}
	}
	sort(b+1,b+1+l,cmp);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=l;i++){
		int f1=find(b[i].u),f2=find(b[i].v); 
		if(f1==f2)break;
		ans+=b[i].w;
		f[f2]=f1;
	}
	cout<<ans;
	return 0;
}

