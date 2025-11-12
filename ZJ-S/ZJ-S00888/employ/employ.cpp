#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int c[509];
int a[509];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,f=0,cnt=0;
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)cnt++;
		if(s[i-1]=='0')f=1;
	}
	if(!f){
		if(n-cnt<m){
			cout<<0;
		}
		else{
			int ans=1;
			for(int i=1;i<=n;i++){
				ans=ans*i%MOD;
			}
			cout<<ans;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			a[i]=i;
		}
		int ans=0;
		do{
			int t=0,now=0;
			for(int i=1;i<=n;i++){
				if(s[i-1]=='1'&&c[a[i]]>t){
					now++;
				}
				else{
					t++;
				}
			}
			if(now>=m){
				ans++;
			}
		}while(next_permutation(a+1,a+1+n));
		cout<<ans<<'\n';
	}
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/