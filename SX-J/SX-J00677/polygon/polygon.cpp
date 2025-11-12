#include<bits/stdc++.h>
#define endl '\n'
#define endline putchar('\n')
#define qwe putchar(' ')
//#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> PII;
typedef long long ll;
inline int read(){
	int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int n;
int a[5010][2],vis[5010],b[5010];
const int MOD=998244353;
int ans;
inline void awa(){
	for(int i=1;i<=5;i++){
		cout<<b[i]<<' ';
	}
	endline;
}
inline void dfs(int k,int maxn,int sum){
	if(k>2) if(sum>maxn*2) ans=(ans+1)%MOD,awa();
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&a[i][1]>a[k][1]){
			vis[i]=1;
			b[k+1]=i;
			dfs(k+1,max(maxn,a[i][0]),sum+a[i][0]);
			b[k+1]=0;
			vis[i]=0;
		}
	}
}
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i][0]=read(),a[i][1]=i;
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
