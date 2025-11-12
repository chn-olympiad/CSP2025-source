#include<bits/stdc++.h>
using namespace std;
const int N=505,MOD=998244353;
int n,m,c[N],ans,flag[N];
string s;
inline int read(){
	int t=1,tot=0;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		tot=tot*10+ch-'0';
		ch=getchar();
	}
	return tot*t;
}
inline void dfs(int x,int sum){
	if(sum+n-x+1<m) return;
	if(x>n){
		if(sum>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!flag[i]){
			flag[i]=1;
			if(s[x-1]=='1' && x-1-sum<c[i]) dfs(x+1,sum+1);
			else dfs(x+1,sum);
			flag[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(); m=read();
	getline(cin,s);
	for(int i=1;i<=n;i++) c[i]=read();
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
