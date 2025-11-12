#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int cnt;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		if(t) cnt++;
	}
	long long ans=0,asn=0;
	if(cnt<m){
		cout<<0;
		return 0;
	}
	for(int i=m;i<=cnt;i++){
		ans+=pow(2,i);
	}
	cout<<ans;
	return 0;
}                                           
