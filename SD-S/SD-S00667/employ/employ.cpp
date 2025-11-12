#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')  f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1ll)+(x<<3ll)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int const N=1e6+5;
int n,m,ans,cnt;
int s[18],a[18],c[18];
bool vis[18];
void dfs(int u,int x){
	if(u==n+1){
		
		if(n-x>=m){
			if(n-x>=m)
			ans++;
		}   
		
		return;
	}
	if(n-x<m)  return;
	for(int i=1;i<=n;i++){
		if(vis[i])  continue;
		vis[i]=1;
		a[u]=i;
		if(x<c[i]){
			if(s[u]==0)  dfs(u+1,x+1);
		    else dfs(u+1,x);
		}
		else dfs(u+1,x+1); 
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++){
    	char ch;
    	cin>>ch;
    	s[i]=ch-'0';
	}  
    for(int i=1;i<=n;i++)  c[i]=read();
    if(n<=18){
    	dfs(1,0);
        cout<<ans;
        return 0;
	}
    cout<<0;
	return 0;
}

