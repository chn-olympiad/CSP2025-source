#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,mod=998244353;
inline int read(){
    int x=0,fg=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fg=1; ch=getchar();}
    while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    return fg?(~(x-1)):x;
}
int n,m,ans;
int a[N],b[N],d[N];
char c[N];
int cal(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(c[i]=='0'||a[d[i]]<=cnt)
			cnt++;
	}
	return cnt>n-m?0:1;
}
void dfs(int x){
	if(x==n+1){ans=(ans+cal())%mod;}
	for(int i=1;i<=n;i++)
		if(!b[i]) b[i]=1,d[x]=i,dfs(x+1),b[i]=0;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=read(),m=read();
    scanf("%s",c+1);
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);
    dfs(1);printf("%lld\n",ans);
    return 0;
}
//sjz2010 orz I_AK_CTS orz

