#include <bits/stdc++.h>
using namespace std;
const int maxn=20;
int n,m,i,ans,res,jc[maxn],f[maxn],c[maxn],vis[maxn];
char s[maxn];
void sc(int t,int x){
	int i;
	if(n-x<m) return ;
	if(t>n){
		if(n-x>=m) ans++;
		return ;
	}
	for(i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			if(s[t]=='0'||x>=c[i]) sc(t+1,x+1);
			else sc(t+1,x);
			vis[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s+1;
	for(i=1;i<=n;i++) cin>>c[i];
	if(n<=18){
		sc(1,0);
		cout<<ans;
	}
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
