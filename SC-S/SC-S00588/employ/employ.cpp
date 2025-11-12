#include<iostream>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,s[505],c[505],a[505],ans,zer;
bool used[505];
void dfs(int x){
	if (x==n+1){
		int fai=0,suc=0;
		for (int i=1;i<=n;++i){
			if (fai>=c[a[i]]){
				++fai;
			}
			else if (s[i]==0) ++fai;
			else ++suc;
		}
		if (suc>=m){
			++ans;
		}
		return ;
	}
	for (int i=1;i<=n;++i){
		if (!used[i]){
			a[x]=i;
			used[i]=1;
			dfs(x+1);
			used[i]=0;
		}
	}
}
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;++i){
		scanf("%1d",&s[i]);
	}
	for (int i=1;i<=n;++i){
		c[i]=read();
		if (c[i]==0){
			++zer;
		}
	}
	if (n<=10){
		dfs(1);
		cout << ans;
	}
	return 0;
}
/*
1234
1243
1324
*/
