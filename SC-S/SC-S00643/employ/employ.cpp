#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=505;
int c[N];
const int mod=998244353;

signed main(){

	ios::sync_with_stdio(0),cin.tie(0);

	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	bool f1=true;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=1) f1=false;
	}
	if(m==n){
		for(int i=0;i<s.size();i++){
			if((int)s[i]==48){
				cout<<0;
				return 0;
			}
		}
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cout<<0;
				return 0;
			}
		}
		int cnt=1;
		for(int i=1;i<=n;i++){
			cnt*=i;
		}
		cout<<cnt;
		return 0;
	}
//	else if(f1=true){
//		
//	}


	return 0;
}
