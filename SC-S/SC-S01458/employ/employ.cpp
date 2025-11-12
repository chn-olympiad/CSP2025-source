#include<bits/stdc++.h>
using namespace std;
int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
	return s*f;
}
int n,m,ans;
string s;
int c[505];
bool vis[505];
void dfs(int x,int cnt,int pre){
	if(x==n+1){
		if(cnt>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			int k=cnt,p=pre;
			if(s[x]=='0'||pre>=c[i]) p++;
			else if(s[x]=='1') k++;
			dfs(x+1,k,p); 
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) c[i]=read();
	dfs(1,0,0);
	cout<<ans;
	return 0;
} 
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/