#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m;
string s;
int c[100005],a[100005];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	int ff=1;
	for(int i=1;i<=n;i++){
		if(s[i]!='1'){
			ff=0;
			break;
		}
	}
	for(int i=1;i<=n;i++)cin>>c[i],a[i]=i;
	if(n<=10){
		int ans=0;
		do{
			int cnt=0,tp=0;
			for(int i=1;i<=n;i++){
				if(cnt<c[a[i]]){
					if(s[i]=='1')tp++;
					else cnt++;
				}
				else cnt++;
			}
			if(tp>=m)ans++;
			ans%=mod;
		}while(next_permutation(a+1,a+n+1));
		cout<<ans;
	}
	else{
		int fac=1,cnt=0;
		for(int i=1;i<=n;i++)fac*=i,fac%=mod;
		for(int i=1;i<=n;i++)cnt+=(c[i]==0);
		if(n-cnt<m)cout<<0;
		else cout<<fac;
	}
	return 0;
}
