#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace l_mid_r{
	const int N=15,mod=998244353;
	int n,m,c[N],a[N],ans,now,cnt;
	char ch[N];
	bool vis[N];
	inline int rd(){
		int x=0,f=1;char ch=getchar();
		while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
		while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
		return x*f;
	}
	void dfs(int x){
		if(x==n+1){
			now=0,cnt=0;
			for(int i=1;i<=n;i++){
				if(now<c[a[i]]&&ch[i]=='1') cnt++;
				else now++;
			}
			if(cnt>=m) ans++;
			return ;
		}
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			vis[i]=1,a[x]=i,dfs(x+1);
			vis[i]=0;
		}
	}
	int main(){
		freopen("employ.in","r",stdin);
		freopen("employ.out","w",stdout);
		cin >> n >> m;
		for(int i=1;i<=n;i++) cin >> ch[i];
		for(int i=1;i<=n;i++) cin >> c[i];
		if(n<=10){
			dfs(1);
			cout << ans;
		}else cout << 0;
		return 0;
	}
}
signed main(){return l_mid_r::main();}
