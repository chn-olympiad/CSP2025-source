#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int ans;
int inline read()
{
	int x=0;
	char c=getchar();
	while(c<'0' || c>'9'){
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int n,m,fl,cnt,p[505],a[505];
int sa,sm;
string s;
int jc(int x){
	int o=1;
	for(int i=1;i<=x;i++) o*=i;
	return o; 
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin >> s;
	for(int i=1;i<=n;i++) p[i]=read();
	for(int i=0;i<s.length();i++){
		if(s[i]=='0') sa=1;
		if(s[i]=='0') a[i+1]=0;
		else a[i+1]=1;
	}
	if(m==n){
		if(sa==1) cout << 0;
		else{
			ans=1;
			for(int i=1;i<=n;i++){
				ans*=i;
				ans%=mod;
			}
			cout << ans%mod;
		} 
		return 0;
	}
	if(sa==0){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout << ans%mod;
		return 0;
	}
	for(int i=1;i<=jc(n);i++){
		cnt=0,fl=0;
		for(int j=1;j<=n;j++){
			if(fl>=p[j]){
				fl++;
				continue;
			}
			if(s[j-1]=='0'){
				fl++;
			}
			else{
				cnt++;
			}
		}
		if(cnt>=m) ans++;
		next_permutation(p+1,p+1+n);
	}
	cout << ans%mod;
	return 0;
}
