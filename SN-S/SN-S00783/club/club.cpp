#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+5;
ll t,n,maxnb = -1;
ll a[N],b[N],c[N],maxn[N][4],d[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ll neb = n/2;
		for(ll i=1;i<=n;i++){
			a[i] = 0;
			b[i] = 0;
			c[i] = 0;
			d[i] = 0;
			maxn[i][1] = 0;
			maxn[i][2] = 0;
			maxn[i][3] = 0;
		}
		for(ll i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			maxn[i][1] = a[i];
			maxn[i][2] = b[i];
			maxn[i][3] = c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				d[i] = a[i];
			}
			if(b[i]>=a[i]&&b[i]>=c[i]){
				d[i] = b[i];
			}
			if(c[i]>=a[i]&&c[i]>=b[i]){
				d[i] = c[i];
			}
		}
		ll sum=0;
		ll cnt=n;
		ll cntt[4]={};
		for(ll i=n;i>=1;i--){
			if(cnt<=0){
				break;
			}
			if(maxn[i][1]>=maxn[i][2]&&maxn[i][1]>=maxn[i][3]&&cntt[1]<neb){
				sum+=maxn[i][1];
				//cout<<maxn[i][1]<<" ";
				cntt[1]++;
				cnt--;
				continue;
			}else{
				if(maxn[i][2]>=maxn[i][3]&&cntt[2]<neb){
					sum+=maxn[i][2];
					//cout<<maxn[i][2]<<" ";
					cntt[2]++;
					cnt--;
					continue;
				}
				if(maxn[i][3]>=maxn[i][2]&&cntt[3]<neb){
					sum+=maxn[i][3];
					//cout<<maxn[i][3]<<" ";
					cntt[3]++;
					cnt--;
					continue;
				}
			}
			if(maxn[i][2]>=maxn[i][1]&&maxn[i][2]>=maxn[i][3]&&cntt[2]<neb){
				sum+=maxn[i][2];
				//cout<<maxn[i][2]<<" ";
				cntt[2]++;
				cnt--;
				continue;
			}else{
				if(maxn[i][1]>=maxn[i][3]&&cntt[1]<neb){
					sum+=maxn[i][1];
					//cout<<maxn[i][1]<<" ";
					cntt[1]++;
					cnt--;
					continue;
				}
				if(maxn[i][3]>=maxn[i][1]&&cntt[3]<neb){
					sum+=maxn[i][3];
					//cout<<maxn[i][3]<<" ";
					cntt[3]++;
					cnt--;
					continue;
				}
			}
			if(maxn[i][3]>=maxn[i][2]&&maxn[i][3]>=maxn[i][1]&&cntt[3]<neb){
				sum+=maxn[i][3];
				//cout<<maxn[i][3]<<" ";
				cntt[3]++;
				cnt--;
				continue;
			}else{
				if(maxn[i][2]>=maxn[i][1]&&cntt[2]<neb){
					sum+=maxn[i][2];
					//cout<<maxn[i][2]<<" ";
					cntt[2]++;
					cnt--;
					continue;
				}
				if(maxn[i][1]>=maxn[i][2]&&cntt[1]<neb){
					sum+=maxn[i][1];
					//cout<<maxn[i][1]<<" ";
					cntt[1]++;
					cnt--;
					continue;
				}
			}
			if(cnt<=0){
				break;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
