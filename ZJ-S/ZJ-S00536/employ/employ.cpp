#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=0;
string s;
int a[501],c[501];
bool b[501];
long long check(int x){
	if(x==1) return 1;
	else return (x*(check(x-1)))%998244353;
}
void dfs(int t,int k){
	if(k>=m){
		ans=(ans+(check(t)))%998244353;
		return;
	}
	else if(t==0) return;
	else{
		for(int i=1;i<=n;i++){
			if(b[i]){
				b[i]=false;
				if(c[i]==1&&a[i]>(n-t-k)) dfs(t-1,k+1);
				else dfs(t-1,k);
				b[i]=true;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(b+1,true,n);
	int t=0;
	cin>>s;
	for(int i=0;i<s.length();i++){
		t+=s[i]-'0';
		c[i+1]=int(s[i]-'0');
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(t==n){
		ans=check(n);
	}
	else dfs(n,0);
	printf("%lld",ans);
	return 0;
}
