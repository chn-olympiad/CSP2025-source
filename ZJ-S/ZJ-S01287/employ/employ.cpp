#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[510],p[510];
char s[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			cnt++;
		}
	}
	if(cnt<m){
		cout<<0;
		return 0;
	}
	if(n>10){
		long long ans=1;
		for(int i=2;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
	}else{
		int ans=0;
		for(int i=1;i<=n;i++){
			p[i]=i;
		}
		do{
			int k=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='0'){
					k++;
					continue;
				}
				if(k>=a[p[i]]){
					k++;
					continue;
				}
			}
			if(n-k>=m){
				ans++;
				ans%=mod;
			}
		}while(next_permutation(p+1,p+n+1));
		cout<<ans;
	}
	return 0;
}