#include<bits/stdc++.h>
using namespace std;

const long long N = 1e3+5,p = 998244353;
long long i,j,k,l,n,m,a[N],ans,f[N],ss[N],flag; 
string s;

long long jie(long long n){
	long long x = 1;
	for(long long i = 2;i <= n;i ++){
		x = x*i%p;
	}
	return x;
}

void dfs(long long cnt,long long len){
	if(cnt == m){
		ans += jie(n-len);
		return ;
	}
	if(len == n){
		return ;
	}
	for(int i = 1;i <= n;i ++){
		if(f[i]){
			f[i] = 0;
			if(ss[len+1] >= a[i]){
				dfs(cnt,len+1);
			}else{
				dfs(cnt+1,len+1);
			}
			f[i] = 1;
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n>> m;
	cin >> s;
	flag = 1;
	for(i = 0;i < s.size();i ++){
		if(s[i] == '0')flag = 0;
	}
	if(flag){
		cout << jie(n);
		return 0;
	}
	for(i = 1;i <= n;i ++){
		cin >> a[i];
	}
	for(i = 1;i <= n;i ++){
		ss[i] = ss[i-1];
		if(s[i-1] == '0') ss[i] ++;
	}
	ans = 0;
	for(i = 1;i <= n;i ++){
		f[i] = 1;
	}
	for(i = 1;i <= n;i ++){
		f[i] = 0;
		if(s[0] == '1'&&a[i] > 0)dfs(1,1);
		else dfs(0,1);
		f[i] = 1;
	}
		cout << ans;
	return 0;
}