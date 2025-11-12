#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cassert>
int n,k;
const int maxn=500+5,mod=998244353;
char tmp[maxn];
std::string mp;
int a[maxn];
namespace Force{
	int v[maxn],len=0,cnt=0,in=0,out=0;
	void dfs(){
		if(len==n){
			int out=0,in=0;
			for(int i=1;i<=len;i++){
				if(out>=a[v[i]]||mp[i-1]=='0') out++;
				else in++; 
			}
			if(in>=k) cnt++;
			cnt%=mod;
			return;
		}
		for(int i=1;i<=n;i++){
			bool flag=true;
			for(int j=1;j<=len;j++) if(i==v[j]) flag=false;
			if(flag){
				v[++len]=i;
				dfs();
				v[len--]=0;
			}
		}
	}
	void solve(){
		len=0,cnt=0;
		dfs();
		printf("%d\n",cnt);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&k,&tmp[1]);
	mp=&tmp[1];
	for(int i=1;i<=n;i++) scanf("%d",&a[i]); 
	Force::solve();
	return 0;
}
