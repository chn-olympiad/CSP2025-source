#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n,m,ans;
int c[N];
long long p[N];
char s[N];
long long he=1;
void dfs(int g){
	he=he*g;
	if(g>1)return dfs(g-1);
	if(g==1){
	ans=he;
	}
}
void check(int x,int y){
	int l=0,f=0;
	for(int i=1;i<=n;i++){
		if(s[i]==0&&f!=c[i]) l++;
		else {
			f++;
		}
		if(l==m){
			dfs(n);
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int j=1;j<=n;j++){
		check(s[j],c[j]);
	}
	p[n]=ans%998244353;
	cout<<p[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}