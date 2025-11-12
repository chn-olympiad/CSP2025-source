#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
long long n,m,c[505],ans=1;
string s;
int flaga=1; 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(s[i]==0) flaga=0;
	}
//	cout<<s<<" "<<s.size()<<" ";
	if(flaga){
		for(int i=1;i<=s.size();i++){
			ans*=i;
//			cout<<i<<" ";
			ans%=998244353;
		}
	}
	cout<<ans;
	return 0;
}