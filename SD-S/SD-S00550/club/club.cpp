#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a1[100001],a2[100001],a3[100001],p[4],cz1[100001],cz2[100001],cz3[100001];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1; i<=t; i++) {
		int n;
		cin>>n;
		ll c1=0,c2=0,c3=0;
		for(int j=1; j<=n; j++) {
			cin>>p[1]>>p[2]>>p[3];
			ll f=max(p[1],p[2]);
			if(max(f,p[3])==p[1]) {
				c1++;
				a1[c1]=p[1];
				sort(p+1,p+4);
				cz1[c1]=p[3]-p[2];
			} else if(max(f,p[3])==p[2]) {
				c2++;
				a2[c2]=p[2];
				sort(p+1,p+4);
				cz2[c2]=p[3]-p[2];
			} else {
				c3++;
				a3[c3]=p[3];
				sort(p+1,p+4);
				cz3[c3]=p[3]-p[2];
			}
		}
		ll num=0;
		for(ll i=1; i<=c1; i++) {
			num+=a1[i];
		}
		for(ll i=1; i<=c2; i++) {
			num+=a2[i];
		}
		for(ll i=1; i<=c3; i++) {
			num+=a3[i];
		}
		if(c1>n/2) {
			sort(cz1+1,cz1+1+c1);
			for(ll i=1; i<=c1-n/2; i++) {
				num-=cz1[i];
			}
			cout<<num<<endl;
		} else if(c2>n/2) {
			sort(cz2+1,cz2+1+c2);
			for(ll i=1; i<=c2-n/2; i++) {
				num-=cz2[i];
			}
			cout<<num<<endl;
		} else if(c3>n/2) {
			sort(cz3+1,cz3+1+c3);
			for(ll i=1; i<=c3-n/2; i++) {
				num-=cz3[i];
			}
			cout<<num<<endl;
		}else{
			cout<<num<<endl;
		}	
	}
	return 0;
}

