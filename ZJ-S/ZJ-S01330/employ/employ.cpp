#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
bool s[509];
int n,m;
int c[509];
int cnt=0,cnt1=0,cnt2=0;
bool st[509];
void dfs(int cc,int sum){
	if(cc>n){
		if(n-sum>=m){
			cnt++;
			cnt%=M;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(st[i]) continue;
		st[i]=1;
		if(sum>=c[i]) dfs(cc+1,sum+1);
		else dfs(cc+1,sum+s[i]);
		st[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	char ss[509];
	cin>>ss;
	for(int i=1;i<=n;i++){
		s[i]=ss[i]-'0';
		s[i]=!s[i];
		if(s[i]==0) cnt1++;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) cnt2++;
	}
	if(cnt1==n){
		if(m+cnt2>n){
			cout<<0;
			return 0;
		}
		int s=1;
		for(int i=1;i<=cnt2;i++){
			s*=i;
		}
		cout<<s;
	}
	dfs(1,0);
	cout<<cnt%M;
	return 0;
}
