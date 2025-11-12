#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace l_mid_r{
	const int N=1e5+5;
	int T,n,m,a[N][3],ans;
	int now[3],q[N],cs[N],top;
	bool c[3];
	inline int rd(){
		int x=0,f=1;char ch=getchar();
		while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
		while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
		return x*f;
	}
	int main(){
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
		T=rd();
		while(T--){
			n=rd(),top=0,ans=0;
			memset(now,0,sizeof now);
			memset(c,0,sizeof c);
			for(int i=1;i<=n;i++) a[i][0]=rd(),a[i][1]=rd(),a[i][2]=rd();
			for(int i=1;i<=n;i++){
				int u=max(a[i][0],max(a[i][1],a[i][2]));
				ans+=u;
				if(a[i][0]==u) now[0]++,cs[i]=0;
				else if(a[i][1]==u) now[1]++,cs[i]=1;
				else now[2]++,cs[i]=2;
			}
			int k=max(now[0],max(now[1],now[2]));
			if(k<=n/2){
				printf("%lld\n",ans);
				continue;
			}else m=k-n/2;
			if(k==now[0]) c[0]=1;
			else if(k==now[1]) c[1]=1;
			else c[2]=1;
			for(int i=1;i<=n;i++){
				if(c[cs[i]]){
					int u=0;
					for(int j=0;j<=2;j++){
						if(j==cs[i]) continue;
						u=max(u,a[i][j]);
					}
					q[++top]=a[i][cs[i]]-u;
				}
			}
			sort(q+1,q+top+1);
			for(int i=1;i<=m;i++) ans-=q[i];
			printf("%lld\n",ans);
		}
		return 0;
	}
}
signed main(){return l_mid_r::main();}
