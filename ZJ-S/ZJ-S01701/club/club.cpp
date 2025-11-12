#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct shu{
	ll x;
	ll y;
	ll z;
	ll vis;
};
bool cmp(shu z1,shu z2){
	if(z1.x-z1.y!=z2.x-z2.y) return z1.x-z1.y>z2.x-z2.y;
	else if(z1.x!=z2.x) return z1.x>z2.x;
	else return z1.y>z2.y;
}
bool cmp1(shu z1,shu z2){
	if(z1.y-z1.z!=z2.y-z2.z) return z1.y-z1.z>z2.y-z2.z;
	else if(z1.y!=z2.y) return z1.y>z2.y;
	else return z1.z>z2.z;
}
bool cmp2(shu z1,shu z2){
	if(z1.z!=z2.z) return z1.z>z2.z;
}
bool cmp3(shu z1,shu z2){
	if(z1.x!=z2.x) return z1.x>z2.x;
	
}
bool cmp4(shu z1,shu z2){
	if(z1.y!=z2.y) return z1.y>z2.y;
	
}
bool cmp5(shu z1,shu z2){
	if(z1.z!=z2.z) return z1.z>z2.z;
	
}

ll b[100005];
shu a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	cin>>t;
	for(ll i=1;i<=t;i++){
	    memset(a,0,sizeof a);
	    memset(b,0,sizeof b);
		ll n;
		cin>>n;
		ll s=0;
		for(ll j=1;j<=n;j++){
			cin>>a[j].x>>a[j].y>>a[j].z;
			a[j].vis=0;
		}
		sort(a+1,a+1+n,cmp);
		for(ll j=1;j<=n;j++){
		    b[j]=max(max(a[j].x,a[j].y),a[j].z);
		}
        ll cc=0;
        for(ll j=1;j<=n;j++){
        	if(cc<n/2){
        		if(b[j]==a[j].x){
        			s+=a[j].x;
        			cc++;
        			a[j].vis=1;
				}
			}
			else break;
		}
		sort(a+1,a+1+n,cmp1);
		ll cc1=0;
		for(ll j=1;j<=n;j++){
        	if(cc1<n/2){
        		if(a[j].y>=a[j].z&&a[j].vis==0){
        			s+=a[j].y;
        			cc1++;
        			a[j].vis=1;
				}
				
			}
			else break;
		}
		sort(a+1,a+1+n,cmp2);
		ll cc2=0;
		for(ll j=1;j<=n;j++){
        	if(cc2<n/2){
        		if(a[j].vis==0){
        			s+=a[j].z;
        		    cc2++;
        		    a[j].vis=1;
				}
			}
			else break;
		}
		
		sort(a+1,a+1+n,cmp3);
        for(ll j=1;j<=n;j++){
        	if(cc<n/2){
        		if(a[j].vis==0){
        			s+=a[j].x;
        			cc++;
        			a[j].vis=1;
				}
			}
			else break;
		}
		sort(a+1,a+1+n,cmp4);
		for(ll j=1;j<=n;j++){
        	if(cc1<n/2){
        		if(a[j].vis==0){
        			s+=a[j].y;
        			cc1++;
        			a[j].vis=1;
				}
				
			}
			else break;
		}
		sort(a+1,a+1+n,cmp5);
		for(ll j=1;j<=n;j++){
        	if(cc2<n/2){
        		if(a[j].vis==0){
        			s+=a[j].z;
        		    cc2++;
        		    a[j].vis=1;
				}
			}
			else break;
		}
		cout<<s<<"\n";
	}
		
	return 0;
}

