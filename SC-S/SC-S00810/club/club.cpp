#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+6;
ll a[N][3],x[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	cin>>t;
	while(t--){
		ll n,ans=0;
		cin>>n;
		queue<ll>q[4];
		for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=n;i++){
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])
				q[1].push(i);
			else if(a[i][2]>a[i][3]&&a[i][2]>a[i][1])
				q[2].push(i);
			else
				q[3].push(i);
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		for(int i=1;i<=3;i++){
			if(q[i].size()>n/2){
				ll k=0;
				ll z=q[i].size();
				while(!q[i].empty()){
					ll z=q[i].front();q[i].pop();
					if(i==1)
						x[++k]=max(a[z][1],max(a[z][2],a[z][3]))-max(a[z][2],a[z][3]);
					else if(i==2)
						x[++k]=max(a[z][1],max(a[z][2],a[z][3]))-max(a[z][1],a[z][3]);
					else
						x[++k]=max(a[z][1],max(a[z][2],a[z][3]))-max(a[z][2],a[z][1]);
				}
				sort(x+1,x+1+k);
				for(int i=1;i<=z-n/2;i++)
					ans-=x[i];
			}
		}
		cout<<ans<<"\n";
	}
}