#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,m,c[10007],res=0;
int tmp[10007];
bool vis[10007];
string s;
inline int rd(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void dfs(int x){
	if(x==n+1){
		int sum=0;
		for(int i=1;i<=n;i++)
		if(s[i-1]=='0'||i-1-sum>=c[tmp[i]]){
			
		}else sum++;
		if(sum>=m)res++;
		return;
	}
	for(int i=1;i<=n;i++)
	if(!vis[i]){
		vis[i]=1;
		tmp[x]=i;
		dfs(x+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=rd();m=rd();
	cin>>s;
	for(int i=1;i<=n;i++)c[i]=rd();
	dfs(1);
	cout<<res;
}

//CCF qiu ni le gei wo gou qi gei wo yi deng
