#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,q;
string a[N],b[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	while(q--){
		ll ans=0;
		string x,y;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			string x2="",y2="";
			if(x.find(a[i])>y.size()-1||y.find(b[i])>y.size()-1) continue;
			int xx=x.find(a[i]),yy=y.find(b[i]);
			for(int j=0;j<=xx;j++) x2+=x[j];
			x2+=a[i];
			for(int j=xx+1;j<x.size();j++) x2+=x[j];
			for(int j=0;j<=yy;j++) y2+=y[j];
			y2+=a[i];
			for(int j=yy+1;j<y.size();j++) y2+=y[j];
			if(x2==y2) ans++;
		}
		cout<<ans<<"\n";
//		cin>>a[1]>>b[1];
//		cout<<0<<"\n";
	}
	return 0;
}
