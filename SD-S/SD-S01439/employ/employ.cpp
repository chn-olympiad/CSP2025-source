#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
const int N=505,MOD=998244353;
long long a[N],flag[N];
long long ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	getline(cin,s);
	s=' '+s;
	flag[0]=0;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=s.size();++i){
		if(s[i]=='0'){
			flag[i]=flag[i-1]+1;
		}else {
			flag[i]=flag[i-1];
		}
	}
	if(m==1){
		for(int i=1;i<=n;++i){
			if(a[i]>=flag[i]){
				ans=ans+i*(i-flag[i]);
				ans%=MOD;
			}
		}
		cout<<ans%MOD<<"\n";
		return 0;
	}
	for(int i=1;i<=n;++i){
		if(a[i]>=flag[i]){
			ans=ans+i*(i-flag[i]);
			ans%=MOD;
		//	cout<<ans<<"\n";
		}
	}
	cout<<ans%MOD<<"\n";
	return 0;
}

