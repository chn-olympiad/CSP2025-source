#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long c[505],t[505];
int n,m;
string s;
int dfs(int cnt,int js){
	if(js==m)return 0;
	if(cnt>n)return 1;
	long long sum=0;
	for(int i=0;i<=n;i++){
		if(t[i]!=0){
			t[i]--;
			if(s[cnt]=='1'&&cnt-js<=i){
				sum+=(t[i]+1)*dfs(cnt+1,js+1)%mod;
			}else{
				sum+=(t[i]+1)*dfs(cnt+1,js)%mod;
			}
			sum%=mod;
			t[i]++;
		}
	}
	return sum;
}
int Dfs(int cnt,int js){
	if(cnt-1!=js)return 0;
	if(cnt>n)return 1;
	long long sum=0;
	for(int i=0;i<=n;i++){
		if(t[i]!=0){
			t[i]--;
			if(s[cnt]=='1'&&cnt-js<=i){
				sum+=(t[i]+1)*Dfs(cnt+1,js+1)%mod;
			}else{
				sum+=(t[i]+1)*Dfs(cnt+1,js)%mod;
			}
			sum%=mod;
			t[i]++;
		}
	}
	return sum;
}
int mi(int n){
	if(n==1)return 1;
	return mi(n-1)*n%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	int s1=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		t[c[i]]++;
		s1+=(s[i]=='1');
	}
	if(n==1){
		if(s[1]=='0'||c[1]==0){
			cout<<"0";
		}else cout<<1;
		return 0;
	}
	else if(m==n){
		cout<<Dfs(1,0);
		return 0;
	}else{
		cout<<(mi(n)-dfs(1,0)+mod)%mod;
		return 0;
	}
	return 0;
}

