#include<bits/stdc++.h>
#define int long long
#define N 1010
using namespace std;
int n,k,i,m,fx,t,ans,j,fy,cnt,f[N],c[N];
struct no{
	int x,y,z;
}a[N];
bool cmp(no q,no h){
	return q.z<h.z;
}
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;t=m;
	for(i=1;i<=m;i++)cin>>a[i].x>>a[i].y>>a[i].z;
	for(i=1;i<=k;i++){
		cin>>c[i];
		for(j=1;j<=n;j++)t++,cin>>a[t].z,a[t].x=i,
		a[t].y=j;
	}
	sort(a+1,a+1+t,cmp);
	for(i=1;i<=n+k;i++)f[i]=i;
	for(i=1;i<=t;i++){
		fx=find(a[i].x),fy=find(a[i].y);
		if(f[fx]!=fy){
			f[fx]=fy;
			cnt++,ans+=a[i].z;
		}
		if(cnt==n-1+k)break;
	}
	cout<<ans<<"\n";
	return 0;
}
/*
		for(i=1;i<=d;i++)k++,x[k]=rand()%n+1,
		y[k]=rand()%m+1,f[x[k]][y[k]]=11;
		f[xb][yb]=1;
		f[xa][ya]=3;
		system("cls");
	}
	return 0;
}
*/