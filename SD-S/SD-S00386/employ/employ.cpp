#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
int n,m,c[10010],flag,ans,cnt,f[1010],p[1010];
string s;
void dfs(int x){
	cnt=0;
	int res=0;
	for(int i=1;i<=x-1;i++){
		if(s[i-1]-'0'==0 || c[p[i]]<=cnt) cnt++; 
		else if(c[p[i]] > cnt){
			++res;
		}	
	}
	if(cnt > n-m) return;
	if(x==n+1){
		cnt=0;
		res=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]-'0'==0 || c[p[i]]<=cnt) cnt++; 
			else if(c[p[i]] > cnt){
				++res;
			}
			
		}
		if(res>=m) {
			//for(int i=1;i<=n;i++) cout<< p[i]<<' ';
			//cout<<'\n';
			++ans;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			p[x]=i;
			dfs(x+1);
			f[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>> s;
	for(int i=0;i<n;i++) {
		if(s[i]-'0'==0) flag=0;
	}
	for(int i=1;i<=n;i++)	{
		c[i]=read();
	}
	dfs(1);
	cout<<ans;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
