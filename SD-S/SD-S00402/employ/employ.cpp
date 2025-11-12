#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int n,m,a[5001],c[5001],f,ans;
int M=998244353;
string s;
signed main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i)
		cin>>c[i];
	for(int i=0;i<s.length();++i){
		a[i+1]=s[i]-'0';
		if(s[i]!='1')
			f=1;
	}
		ans=1;
		for(int i=m+1;i<=n;++i){
			ans*=i;
			ans%=M;
		}
		cout<<ans;
	return 0;
}

