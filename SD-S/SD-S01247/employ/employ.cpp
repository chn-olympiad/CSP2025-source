#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
const int N=1e5+5;
const int mod=998244353;
inline int rd(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int n,m;
int ans,cnt;
int s[N],c[N],pre[N],p;
bool vis[N];
void solve(int pos){
	if(pos==n+1){
		ans+=(cnt>=m);
		ans%=mod;
		return;
	}
	for(re int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		if(s[pos]==0&&p<c[i])cnt++;
		else p++;
		solve(pos+1);
		vis[i]=0;
		if(s[pos]==0&&p<c[i])cnt--;
		else p--;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=rd(),m=rd();
	for(re int i=1;i<=n;i++){
		char c=getchar();
		s[i]=(c-'0')^1;
	}
	for(re int i=1;i<=n;i++)c[i]=rd();
	solve(1);
	printf("%d\n",ans);
	return 0;
}


