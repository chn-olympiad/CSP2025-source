#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>

using namespace std;

typedef long long ll;

inline ll readl(){
	ll x=0,y=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')y=-y;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c&15);
		c=getchar();
	}
	return x*y;
}
void writel(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else writel(x/10),putchar(x%10+'0');
}
inline string readstr(){
	string s="";char c=getchar();
	while(c<'0'||c>'1') c=getchar();
	while(c>='0'&&c<='1') s+=c,c=getchar();
	return s;
}
string s;ll n,m,c[1000010],t[10050],ans;
bool vis[100010];
void dfs(ll x,ll now){
	if(x>n){
		if(now>=m)ans++,ans%=998244353;
		return;
	}
	for(ll i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(x+1,now+(s[x-1]=='1'&&x-1-now<c[i]));
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	n=readl(),m=readl();s=readstr();
	for(ll i=1;i<=n;i++){
		c[i]=readl();
	}
	dfs(1,0);
	writel(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
