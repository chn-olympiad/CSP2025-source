#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[100010];
int b[100010];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int f=0,k=0;
	int h=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')f++;
		else k++;
	}
	for(int i=1;i<=n;i++){
		a[i]=i;
		cin>>b[i];
		if(b[i]==0)h++;
	}
	sort(a+1,a+n+1);
	long long ans=0;
	if(n<=10){
		long long q=1;
		for(int i=2;i<=n;i++){
			q*=i;
		}
		while(q--){
			next_permutation(a+1,a+n+1);
			int l=0;
			for(int i=1;i<=n;i++){
				if(l>=b[a[i]]){
					l++;
					continue;
				}
				if(s[i-1]=='0'){
					l++;
				}
			}
			if(n-l>=m){
				ans++;
			}
		}
	}else if(k==s.size()&&h==0){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
	}
	else if(m==1){
		if(k>=1){
			ans=1;
			for(int i=1;i<=n;i++){
				ans*=i;
				ans%=mod;
			}
		}
	}
	if(m==n){
		if(k!=s.size()||h>0)ans=0;
	}
	cout<<ans%mod;
	return 0;
}
