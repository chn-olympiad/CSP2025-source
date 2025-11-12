#include<bits/stdc++.h>
using namespace std;
int n,m,c[501],p=0;
bool a[501],vis[501];
string s;
void dfs(int step,int ch){
	if(step>n){
		if(m+ch<=n){
			p++;
			p%=998244353;
		}return;
	}if(m+ch>n)return;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(ch>=c[i])dfs(step+1,ch+1);
			else dfs(step+1,ch+!a[step]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for(int i=1;i<=n;i++){
		a[i]=s[i-1]=='1';
		cin >> c[i];
	}dfs(1,0);
	cout << p;
	return 0;
}
