#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define PII pair<ll,ll>
#define x first 
#define y second
const int N=1e5+10;
ll T,n,sum,g[N][3],v[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	while(T--){
		memset(g,0,sizeof g);
		priority_queue<PII,vector<PII>,greater<PII> > q0,q1,q2;
		sum=0,n=0;
		cin>>n;
		ll m=n/2;
		bool aaa=1,bbb=1,ccc=1;
		for(int i=1;i<=n;i++){
			cin>>g[i][0]>>g[i][1]>>g[i][2];
			if(g[i][1]||g[i][2])aaa=0;
		}
		if(aaa){
			memset(v,0,sizeof v);
			for(int i=1;i<=n;i++){
				v[i]=g[i][0];
			}
			sort(v+1,v+n+1);
			reverse(v+1,v+n+1);
			for(int i=1;i<=m;i++)sum+=v[i];
			cout<<sum<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			ll ma=max({g[i][0],g[i][1],g[i][2]});
			if(ma==g[i][0]){
				if(q0.size()>=m){
					ll y=q0.top().y;
					ll maxn=max({g[y][0]+g[i][1],g[y][0]+g[i][2],g[y][1]+g[i][0],g[y][2]+g[i][0]});
					if(maxn==g[y][1]+g[i][0]){
						q0.pop();
						q0.push({g[i][0],i});
						q1.push({g[y][1],y});
						sum=sum-g[y][0]+g[y][1]+g[i][0];
					}else if(maxn==g[y][2]+g[i][0]){
						q0.pop();
						q0.push({g[i][0],i});
						q2.push({g[y][2],y});
						sum=sum-g[y][0]+g[y][2]+g[i][0];
					}else if(maxn==g[y][0]+g[i][1]){
						q1.push({g[i][1],i});
						sum=sum+g[i][1];
					}else if(maxn==g[y][0]+g[i][2]){
						q2.push({g[i][2],i});
						sum=sum+g[i][2];
					}
				}else{
					q0.push({g[i][0],i});
					sum+=g[i][0];
				}
			}else if(ma==g[i][1]){
				if(q1.size()>=m){
					ll y=q1.top().y;
					ll maxn=max({g[y][1]+g[i][0],g[y][1]+g[i][2],g[y][0]+g[i][1],g[y][2]+g[i][1]});
					if(maxn==g[y][1]+g[i][0]){
						q0.push({g[i][0],i});
						sum+=g[i][0];
					}else if(maxn==g[y][1]+g[i][2]){
						q2.push({g[i][2],i});
						sum+=g[i][2];
					}else if(maxn==g[y][0]+g[i][1]){
						q1.pop();
						q1.push({g[i][1],i});
						q0.push({g[y][0],y});
						sum=sum-g[y][1]+g[y][0]+g[i][1];
					}else if(maxn==g[y][2]+g[i][1]){
						q1.pop();
						q1.push({g[i][1],i});
						q2.push({g[y][2],y});
						sum=sum-g[y][1]+g[y][2]+g[i][1];
					}
				}else{
					q1.push({g[i][1],i});
					sum+=g[i][1];
				}
			}else if(ma==g[i][2]){
				if(q2.size()>=m){
					ll y=q2.top().y;
					ll maxn=max({g[y][2]+g[i][0],g[y][2]+g[i][1],g[y][0]+g[i][2],g[y][1]+g[i][2]});
					if(maxn==g[y][2]+g[i][0]){
						q0.push({g[i][0],i});
						sum+=g[i][0];
					}else if(maxn==g[y][2]+g[i][1]){
						q1.push({g[i][1],i});
						sum+=g[i][1];
					}else if(maxn==g[y][0]+g[i][2]){
						q2.pop();
						q2.push({g[i][2],i});
						q0.push({g[y][0],y});
						sum=sum-g[y][2]+g[y][0]+g[i][2];
					}else if(maxn==g[y][1]+g[i][2]){
						q2.pop();
						q2.push({g[i][2],i});
						q1.push({g[y][1],y});
						sum=sum-g[y][2]+g[y][1]+g[i][2];
					}
				}else{
					q2.push({g[i][2],i});
					sum+=g[i][2];
				}
			}
		}
		cout<<sum<<"\n";
	}
	
	return 0;
}