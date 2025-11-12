#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],f[505],cnt;
long long ans;string s;
bool pf=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=i;
		if(s[i]!='1')pf=0;
		if(a[i]==0)cnt++;
	}if(cnt>n-m){
		cout<<0;return 0;
	}if(n<=10){
		do{
			int ko=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='0'||ko>=a[f[i]]){
					ko++;
				}
			}
			if(ko<=n-m)ans++;
		}while(next_permutation(f+1,f+n+1));
		cout<<ans;
	}else if(pf){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}cout<<ans;
	}else cout<<0;
	return 0;
}


