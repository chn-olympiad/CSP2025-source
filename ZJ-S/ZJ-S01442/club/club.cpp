#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
inline int read(){
	int s=0,w=1;
	char c=getchar();
	for(;c<'0'||c>'9';w*=(c=='-')?(-1):1,c=getchar());
	for(;c>='0'&&c<='9';s=s*10+c-'0',c=getchar());
	return s*w;
}
int T,n,a[N][5],cnt[5],id[N],b[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		cnt[1]=cnt[2]=cnt[3]=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			int maxn=0;
			for(int j=1;j<=3;j++) a[i][j]=read(),maxn=max(maxn,a[i][j]);
			ans+=maxn;
			for(int j=1;j<=3;j++){
				if(a[i][j]==maxn){
					cnt[j]++,id[i]=j;
					break;
				}
			}
		}
		int mx=max({cnt[1],cnt[2],cnt[3]});
		if(mx>n/2){
			int o=0,tot=0;
			for(int i=1;i<=3;i++) if(cnt[i]>n/2){ o=i; break; }
			for(int i=1;i<=n;i++){
				if(id[i]==o){
					int se=0;
					for(int j=1;j<=3;j++) if(j!=o) se=max(se,a[i][j]);
					b[++tot]=a[i][o]-se;
				}
			}
			sort(b+1,b+tot+1);
			for(int i=1;i<=cnt[o]-n/2;i++) ans-=b[i];
		}
		printf("%d\n",ans);
	}
 	return 0;
}

