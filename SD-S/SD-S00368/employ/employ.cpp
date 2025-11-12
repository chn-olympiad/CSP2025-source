#include<bits/stdc++.h>
using namespace std;
#define LL long long

LL m,n;
LL ans=1;

int main(){
	freopen("employ.in ","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	string a;
	cin>>a;
	LL b=n;
	
	for(int i=1;i<=b;i++){
		LL c;
		cin>>c;
		if(c==0){
			n--;
		}
	}
	
	for(int i=1;i<=b;i++){
		ans*=i;
		ans%=998244353;
	}
//	for(int i=1;i<=b-m;i++){
//		ans*=i;
//		ans%=998244353;
//	}
	
	cout<<ans;
	
	
	
	return 0;
}
