#include <bits/stdc++.h>
using namespace std;
#define int long long
const int P=998244353;
int a[505],p[505],f[505][505],n,m;
string s;
bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(cnt>=a[p[i]]||s[i]=='0') cnt++;
	return n-cnt>=m;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int jc=1,ans=0;
	cin>>n>>m>>s;s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>a[i],p[i]=i;
		jc=jc*i%P;
	}
	if(m==n){
		for(int i=1;i<=n;i++)
			if(s[i]=='0'||a[i]==0){
				cout<<0;
				return 0;
			}
		cout<<jc;
		return 0;
	}
	if(m==1){
		sort(a+1,a+n+1);
		ans=1;
		int jj=0,cnt=0;
		for(int i=1;i<=n;i++){
			while(jj<n){
				if(a[jj+1]<i) jj++;
				else break;
			}
			if(jj==0){
				cout<<jc;
				return 0;
			}
			if(s[i]=='1') ans=(ans*(jj-i+cnt+1))%P;
			else cnt++;
		}
		for(int i=1;i<=cnt;i++) ans=(ans*i)%P;
		cout<<(jc-ans+P)%P;
		return 0;
	}
	if(n>=11){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=jc;i++){
		ans+=check();
		next_permutation(p+1,p+n+1);
	}
	cout<<ans%P;
	return 0;
}
//18:08 finish 24 so excited
//P2441M 保佑我这题24分不挂