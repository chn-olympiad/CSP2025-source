#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
ll T,n,a[N],b[N],c[N],mx,mid,d[10],ans;
vector<ll> G;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		d[1]=0;
		d[2]=0;
		d[3]=0;
		ans=0;
		for(ll i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			mx=max(a[i],max(b[i],c[i]));
			ans+=mx;
			if(a[i]==mx) d[1]++;
			else if(b[i]==mx) d[2]++;
			else if(c[i]==mx) d[3]++;
		}
		for(ll i=1;i<=3;i++){
			if(d[i]>n/2){
				G.clear();
				for(ll j=1;j<=n;j++){
					mx=max(a[j],max(b[j],c[j]));
					if((i==1&&a[j]==mx)||(i==2&&b[j]==mx)||(i==3&&c[j]==mx)){
						mid=a[j]+b[j]+c[j]-mx-min(a[j],min(b[j],c[j]));
						G.push_back(mx-mid);
					}
				}
				sort(G.begin(),G.end());
				for(ll j=0;j<d[i]-n/2;j++){
					ans-=G[j];
				}
				
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
