#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ll n,a[100010],b[100010],c[100010],ans,maxn=0,a1=0,b1=0,c1=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
		ans=n/2;
		for(int i=1;i<=n;i++){
			if(a[i]>=b[i]&&a[i]>=c[i]&&a1<ans){
				a1++;
				maxn+=a[i];
				cout<<a[i]<<" "<<a1<<endl;
			}
			if(a[i]<=b[i]&&b[i]>=c[i]&&b1<ans){
				b1++;
				maxn+=b[i];
				cout<<b[i]<<" "<<b1<<endl;
			}
			if(c[i]>=b[i]&&a[i]<=c[i]&&c1<ans){
				c1++;
				maxn+=c[i];
				cout<<c[i]<<" "<<c1<<endl;
			}
			if(a1==ans){
				for(int i=1;i<=n;i++) a[i]=0;
			}
			if(b1==ans){
				for(int i=1;i<=n;i++) b[i]=0;
			}
			if(c1==ans){
				for(int i=1;i<=n;i++) c[i]=0;
			}
		}
		cout<<maxn<<"\n";
	}
	return 0;
}

