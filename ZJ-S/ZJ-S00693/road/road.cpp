#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000005;
int n,m,k,i,x,y,z,cnt,fx,fy,ans,f[N];
struct no{int start,end,money;}a[N];
bool cmp(no q,no h){return q.money<h.money;}
int find(int x){
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(i=1;i<=n;i++) f[i]=i;
	for(i=1;i<=m;i++)
		cin>>x>>y>>z,
		a[++cnt].start=x,a[cnt].end=y,a[cnt].money=z;
	if(k==0){
		sort(a+1,a+cnt+1,cmp);
		for(i=1;i<=cnt;i++){
			fx=find(a[i].start);fy=find(a[i].end);
			if(fx!=fy) ans=ans+a[i].money,f[fx]=fy;
		}
		cout<<ans;
	}
	else{

	}
	return 0;
}
//16