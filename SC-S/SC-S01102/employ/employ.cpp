#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read(){
	int ans=0,j=1;
	char c=getchar();
	while(c>'9' or c<'0'){
		if(c=='-')
			j=-1;
		c=getchar();
	}
	while(c>='0' and c<='9'){
		ans=(ans<<3)+(ans<<1)+(c^48);
		c=getchar();
	}
	return ans*j;
}
void write(int x){
	if(x<0)
		putchar('-'),
		x=-x;
	if(x>9)
		write(x/10);
	putchar('0'+x%10);
}
string READ(){
	char c=getchar();
	while(c>'1' or c<'0')
		c=getchar();
	string ret="";
	while(c>='0' and c<='1')
		ret+=c,
		c=getchar();
	return ret;
}
const int mod=998244353;
int n,m,s[505],c[505],ans,JC[505];
bool vis[505];
void dfs(int x,int y,int g){//当前第x天正在录用第g人
	if(x-y>c[g] or !s[x]){
		if(m==n)
			return;
	}
	else ++y;
	if(y>=m){
		//剩下的乱排列
		ans+=JC[n-x];
		ans%=mod;
		return;
	}
	if(x==n){
		if(y>=m)
			++ans;
		return;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			vis[i]=1;
			dfs(x+1,y,i);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	JC[0]=1;
	for(int i=1;i<=500;++i)
		JC[i]=JC[i-1]*i%mod;
	n=read(),m=read();
	string str=READ();
	bool ck=1;
	for(int i=1;i<=n;++i){
		s[i]=(str[i-1]=='1');
		if(!s[i])
			ck=0;
	}
	if(ck){
		cout<<JC[n];
		return 0;
	}
	for(int i=1;i<=n;++i)
		c[i]=read();
	sort(c+1,c+n+1);
	for(int i=1;i<=n;++i){
		vis[i]=1;
		dfs(1,0,i);
		vis[i]=0;
	}
	cout<<ans;
	return 0;
}
/*
3 2
101
1 1 2
*/