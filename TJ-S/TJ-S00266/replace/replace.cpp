#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5,p=37,p2=137,mod=1e9+7,mod2=1e9+9;
int n,m,q,ha[N],iha[N],a[N][2][N],siz[N],f[N],b[2][N];
string s[N][2],t1,t2;
struct node{
	int pre,nxt;
}t[N];
inline int read(){int x(0),f(1);char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-') f=-1;for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);return x*f;}
int ksm(int a,int b){
	int res=1;
	for(;b;b>>=1,a=a*a%mod) if(b&1) res=res*a%mod;
	return res;
}
int ss(int a[],int al,int ar){
	return (a[ar]-a[al-1]*ha[ar-al+1]%mod+mod)%mod*iha[al]%mod;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	int cc=clock();
	n=read(),q=read();
	bool flag=0;
	ha[0]=1;iha[1]=p;
	iha[0]=1;iha[1]=ksm(p,mod-2);
	for(int i=2;i<=N-1;i++) ha[i]=ha[i-1]*p%mod,iha[i]=iha[i-1]*iha[1]%mod;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		siz[i]=s[i][0].size();
		for(int j=0;j<siz[i];j++){
			a[i][0][j+1]=(a[i][0][j]*p%mod+s[i][0][j]-'a'+1)%mod;
			a[i][1][j+1]=(a[i][1][j]*p%mod+s[i][1][j]-'a'+1)%mod;
		}
//		printf("%lld %lld\n",a[i][0][siz[i]],a[i][1][siz[i]]);
	}
	while(q--){
		cin>>t1>>t2;
		m=t1.size();
		int l=2e9,r=-1,ans=0;
		for(int i=0;i<m;i++){
			b[0][i+1]=(b[0][i]*p%mod+t1[i]-'a'+1)%mod;
			b[1][i+1]=(b[1][i]*p%mod+t2[i]-'a'+1)%mod;
			if(t1[i]!=t2[i]) l=min(l,i),r=max(r,i);
		}
//		printf("%d %d\n",l,r);
//		for(int i=1;i<=l;i++){
//			for(int j=1;j<=n;j++){
//				printf("%lld %lld\n",ss(b[0],i,i+siz[j]-1),ss(b[1],i,i+siz[j]-1));
//				if(ss(b[0],i,i+siz[j]-1)==a[i][0][siz[j]]&&ss(b[1],i,i+siz[j]-1)==a[i][1][siz[j]]) ans++;
//			}
//		}
		for(int i=0;i<=l;i++){
			for(int j=1;j<=n;j++){
				if(i+siz[j]-1>=m||!(i<=l&&r<=i+siz[j]-1)) continue;
				bool flag=0;
				for(int k=0;k<siz[j];k++){
					if(s[j][0][k]!=t1[i+k]||s[j][1][k]!=t2[i+k]){flag=1;break;}
				}
				if(!flag){
//					printf("%d %d %d\n",j,i,i+siz[j]-1);
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
//	printf("\n%d",clock()-cc);
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
