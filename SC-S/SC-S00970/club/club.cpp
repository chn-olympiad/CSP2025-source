#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
struct k{
	int b[10];
	int flag,ma;
}a[N];
int maxx(k p){
	int maxn=0;
	for(int i=1;i<=3;i++)
		if(i==p.flag) continue;
		else maxn=max(maxn,p.b[i]);
	return maxn;
}
bool cmp(k p,k q){
	return p.ma-maxx(p)>q.ma-maxx(q);
}
int z[10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	int T;cin>>T;
	while(T--){
		memset(z,0,sizeof(z));
		long long ans=0;
		int n,cnt=0;cin>>n;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			a[i].ma=max(x,max(y,z));
			if(a[i].ma==x) a[i].flag=1;
			else if(a[i].ma==y) a[i].flag=2;
			else a[i].flag=3;
			a[i].b[1]=x,a[i].b[2]=y,a[i].b[3]=z; 
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(z[a[i].flag]==n/2){
				ans+=maxx(a[i]);
			}
			else ans+=a[i].ma,z[a[i].flag]++;
		}
		cout<<ans<<"\n";
	}	 
}