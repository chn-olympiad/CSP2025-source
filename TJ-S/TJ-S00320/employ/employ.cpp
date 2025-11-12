#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m;
string s;
int a[505];
int jie[505]={1};
int mod=998244353;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	for (int i=1;i<=n;i++) cin>>a[i];
	bool ok1=1,ok2=1;//quan neng guo / no have cs
	for (int i=0;i<s.size();i++) if (s[i]=='0') ok1=0;
	for (int i=1;i<=n;i++) if (a[i]==0) ok2=0;
	for (int i=1;i<=n;i++) jie[i]=jie[i-1]*i%mod;
	if (m==n){
		if (ok1==0) cout<<0;
		else if (ok2==0) cout<<0;
		else cout<<jie[n];
	}
	else if (m==1){
		sort(a+1,a+1+n);
		int cnt=0,sum=1;
		int l=upper_bound(a+1,a+1+n,0)-a-1;
		for (int i=0;i<s.size();i++){
			if (s[i]=='1'){
				int r=upper_bound(a+1,a+1+n,i-1)-a-1;
				sum=sum*(r-cnt)%mod;
				cnt++;
			}
		}
		int x=jie[n-cnt]*sum%mod;
		cout<<(jie[n]+mod-x)%mod;
	}
	else cout<<jie[n];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
