#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[505],ans,p[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	for (int i=1;i<=n;i++) cin>>a[i],p[i]=i;
	do{
		int cnt=0;
		for (int i=1;i<=n;i++){
			if (cnt>=a[p[i]]){
				cnt++;
				continue;
			}
			if (s[i]=='0') cnt++;
		}
		if (n-cnt>=m){
			ans++;
			ans%=mod;
		}
	}while(next_permutation(p+1,p+n+1));
	cout<<ans<<endl;
	return 0;
}

