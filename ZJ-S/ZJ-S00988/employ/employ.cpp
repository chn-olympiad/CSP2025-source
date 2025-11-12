#include<bits/stdc++.h>
using namespace std;
const long long p=998244353,tt=998244353*998244353;
long long ans,fk[600],bs;
int n,m,f[600],b[600];
bool usd[600];
char s[600];
void dfs(int x,int num,int nb){
	if(x!=0){
		if(s[x]=='1'&&x-1-num<b[nb])num++;
		if(num>=m){
			ans=(ans+fk[n-x])%p;
			return;
		}
		if(x>n||n-x<(m-num+f[n]-f[x]))return;
	}
	for(int i=1;i<=n;i++){
		if(usd[i]==false){
			usd[i]=true;
			dfs(x+1,num,i);
			usd[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0')f[i]=f[i-1]+1;
		else f[i]=f[i-1];
	}	
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]==0)bs++;
	}
	if(n-f[n]<m){
		cout<<0;
		return 0;
	}
	sort(b+1,b+1+n);
	fk[0]=1;
	for(int i=1;i<=n;i++){fk[i]=(fk[i-1]*i)%tt;fk[i-1]=fk[i-1]%p;}
	fk[n]=fk[n]%p;
	 if(m==n&&f[n]!=0)cout<<0;
	else {
		dfs(0,0,0);
		cout<<ans;
	}
	return 0;
}
