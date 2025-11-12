#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+50,M=1e6+10,K=11,X=1e5+1e4+10;
struct node{
	ll x,y,z;
}a[M],b[N],d[X];
bool cmp(node a1,node a2){
	return a1.z<a2.z;
}
ll f[N],v[K],c[K][N];
int find(int x){
	if(f[x]==0){
		return x;
	}
	f[x]=find(f[x]);
	return f[x];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k,cnt=0,x,num,mi=0x3f3f3f3f3f3f3f3f,ans,tot;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	for(int i=1;i<=k;i++){
		cin>>v[i];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(find(a[i].x)!=find(a[i].y)){
			cnt++;
			b[cnt]=a[i];
			f[find(a[i].x)]=find(a[i].y);
		}
		if(cnt==n-1){
			break;
		}
	}
	x=(1<<k)-1;
	for(int i=0;i<=x;i++){
		ans=0;
		num=0;
		cnt=0;
		tot=0;
		for(int j=1;j<=n+k;j++){
			f[j]=0;
		}
		for(int j=1;j<=k;j++){
			if((1<<(j-1))&i){
				ans+=v[j];
				num++;
				for(int p=1;p<=n;p++){
					cnt++;
					d[cnt]={j+n,p,c[j][p]};
				}
			}
		}
		for(int j=1;j<=n-1;j++){
			cnt++;
			d[cnt]=b[j];
		}
		sort(d+1,d+cnt+1,cmp);
		for(int j=1;j<=cnt;j++){
			if(find(d[j].x)!=find(d[j].y)){
				tot++;
				f[find(d[j].x)]=find(d[j].y);
				ans+=d[j].z;
			}
			if(tot==n-1+num){
				break;
			}
		}
		mi=min(mi,ans);
	}
	cout<<mi;
	return 0;
}
