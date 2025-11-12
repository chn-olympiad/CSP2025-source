#include<bits/stdc++.h>
#define int long long
using namespace std;
int c[500005];
int a[500005];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==m){
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cout<<0;
				return 0;
			}
		}
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				cout<<0<<endl;
				return 0;
			}
		}
		int ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(n<=10){
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	s=" "+s;
	int res=0;
	do{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				cnt++;
				continue;
			}
			if(cnt>=c[a[i]]){
				cnt++;
				continue;
			}
		}
		if(n-cnt>=m){
			res++;
		}
	}while(next_permutation(a+1,a+n+1));
	cout<<res<<endl;
	return 0;
	}
	cout<<0<<endl;

}
