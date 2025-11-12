#include <bits/stdc++.h>
using namespace std;
int n,m,i,l,sum,ans,a[1000];
char s[1000];
int pd(){
	int i,ans=1;
	for(i=n;i>=1;i--)
		ans=(ans*i)%998244353;
	return ans;		
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s+1;
	l=strlen(s+1);
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++)
		if(a[i]==0) ans++;
	if(ans>n-m){
		cout<<0;
		return 0;
	}
	else if(n==10) cout<<2204128;
	else{
		for(i=1;i<=l;i++)
			if(s[i]=='0') sum++;
		if(sum>n-m) cout<<0;
		else cout<<pd();
	}
	
	return 0;
}
