//RP++Çó¹ý£¡£¡£¡ 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define inline
const ll N=2e5+10;
ll n,a[N],b[N],c[N];
ll maxx[N];
bool cmp1(ll x,ll y){
	ll tmpa=max(b[x]-a[x],c[x]-a[x]);
	ll tmpb=max(b[y]-a[y],c[y]-a[y]);
	return tmpa<tmpb;
}
bool cmp2(ll x,ll y){
	ll tmpa=max(a[x]-b[x],c[x]-b[x]);
	ll tmpb=max(a[y]-b[y],c[y]-b[y]);
	return tmpa<tmpb;
}
bool cmp3(ll x,ll y){
	ll tmpa=max(b[x]-c[x],a[x]-c[x]);
	ll tmpb=max(b[y]-c[y],a[y]-c[y]);
	return tmpa<tmpb;
}
int mian(){
	cin>>n;
	ll n2=n/2;
	ll ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		maxx[i]=max(a[i],max(b[i],c[i]));
	}
	vector<ll> A,B,C;
	for(int i=1;i<=n;i++){
		if(maxx[i]==a[i]){
			A.pb(i);
		}
		else if(maxx[i]==b[i]){
			B.pb(i);
		}
		else if(maxx[i]==c[i]){
			C.pb(i);
		}
	}
	if(A.size()>n2){
		sort(A.begin(),A.end(),cmp1);
		while(A.size()>n2){
			ll tmp=A[A.size()-1];
			if(b[tmp]-a[tmp]>c[tmp]-a[tmp]){
				B.pb(tmp);
			}
			else{
				C.pb(tmp);
			}
			A.pop_back();
		}
	}
	if(B.size()>n2){
		sort(B.begin(),B.end(),cmp2);
		while(B.size()>n2){
			ll tmp=B[B.size()-1];
//			cout<<tmp<<" ";
			if(a[tmp]-b[tmp]>c[tmp]-b[tmp]){
				A.pb(tmp);
			}
			else{
				C.pb(tmp);
			}
			B.pop_back();
		}
	}
	if(C.size()>n2){
		sort(C.begin(),C.end(),cmp3);
		while(C.size()>n2){
			ll tmp=C[C.size()-1];
			if(b[tmp]-c[tmp]>a[tmp]-c[tmp]){
				B.pb(tmp);
			}
			else{
				A.pb(tmp);
			}
			C.pop_back();
		}
	}
	for(auto i:A){
		ans+=a[i];
	}
	for(auto i:B){
		ans+=b[i];
	}
	for(auto i:C){
		ans+=c[i];
	}
	cout<<ans<<"\n";
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	cin>>t;
	while(t--){
		mian();
	}
	return 0;
}


