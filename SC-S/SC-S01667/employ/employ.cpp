#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 510;
const int Mod = 998244353;
int n,m,c[N],ans=1,a[N],cnt;
char s[N];
int C[N][N],A[N];
bool vis[N],s1=1;
void init(){
	C[1][0]=1,C[0][0]=1;
	A[0]=1;
	for(int i=1;i<N;++i){
		A[i]=(A[i-1]*i)%Mod;
		C[i][0]=1;
		for(int j=1;j<=i;++j){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
		}
	}
}
void dfs(int pos){
	if(pos>n){
		int sum=0,out=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='1'&&out<c[a[i]]) ++sum;
			else ++out;
		}
		if(sum>=m) ++ans;
		ans%=Mod;
		return;
	}
	for(int i=1;i<=n;++i){
		if(vis[i]) continue;
		vis[i]=1;
		a[pos]=i;
		dfs(pos+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	init();
	cin>>n>>m;
	cin>>s+1;
	for(int i=1;i<=n;++i){
		cin>>c[i];
		if(s[i]=='0') s1=0;
		cnt+=(c[i]>0);
	}
	if(n==m){
		if(!s1){
			cout<<0;
			return 0;
		}
		sort(c+1,c+n+1);
		for(int i=1;i<=n;++i){
			int len=1;
			int p=i-1;
			while(i<n&&c[i+1]==c[i]){
				++len;
				++i;
			}
			ans*=C[c[i]-p][i-p]*A[i-p];
		}
		
		cout<<ans;
	}
	else if(s1&&cnt==n){
		cout<<A[n];
	}
	else if(n<=10){
		dfs(1);
		cout<<ans-1;
	}
	else{
		cout<<0;
	}
	return 0;
}