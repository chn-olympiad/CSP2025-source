#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int a[12][12];
int a1,ans=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>a1;
	for(int i=2;i<=n*m;i++){
		int ls;cin>>ls;
		if(ls>a1) ans++;
	}
//	cout<<ans<<endl;
	if(((ans-1)/n+1) &1 ){
		cout<<((ans-1)/n+1)<<' '<< (ans%n==0 ? n : ans%n)<<"\n";
	}else{
		cout<<((ans-1)/n+1)<<' '<< (ans%n==0 ? 1 : n-(ans%n)+1 )<<"\n";
	}
	return 0;
}
