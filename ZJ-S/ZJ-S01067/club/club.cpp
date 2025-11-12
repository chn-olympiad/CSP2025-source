#include<bits/stdc++.h>
using namespace std;
#define ps putchar(' ')
#define pn putchar('\n')
#define In(x) freopen(x".in","r",stdin)
#define Out(x) freopen(x".out","w",stdout)
#define File(x) (In(x),Out(x))

typedef long long ll;

template<typename T> void re( T &t){
	t=0;int f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	do{
		(t=((t<<3)+(t<<1)))+=(ch^48);
		ch=getchar();
	}while(ch>='0' && ch<='9');
	t*=f;
}

void wr(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) wr(x/10);
	putchar(x%10+'0');
}

int t,n,m;
                                                                                                                                                                                                                                                                                                                                                                          
int v[5][100005];
ll f[105][105][105];

int main(){
	File("club");
	re(t);
	while(t--){
		re(n);
		m=n>>1;
		if(n>=200){
			ll ans=0;
			for(int i=1;i<=n;i++){
				re(v[1][i]),re(v[2][i]),re(v[3][i]);
			}
			for(int i=1;i<=n;i++){
				for(int a=m;a>=0;a--){
					if(a>i) continue;
					for(int b=m;b>=0;b--){
						if(a+b>i) continue;
						if(a>0) f[a][b][0]=max(f[a][b][0],f[a-1][b][0]+v[1][i]);
						if(b>0) f[a][b][0]=max(f[a][b][0],f[a][b-1][0]+v[2][i]);
						ans=max(ans,f[a][b][0]);
						//wr(a),ps,wr(b),ps,wr(c),ps,wr(f[a][b][c]),pn;
					}
				}
			}
			wr(ans),pn;
			memset(f,0,sizeof f);
		}
		else{
			ll ans=0;
			for(int i=1;i<=n;i++){
				re(v[1][i]),re(v[2][i]),re(v[3][i]);
			}
			for(int i=1;i<=n;i++){
				for(int a=m;a>=0;a--){
					if(a>i) continue;
					for(int b=m;b>=0;b--){
						if(a+b>i) continue;
						for(int c=m;c>=0;c--){
							if(a+b+c>i) continue;
							if(a>0) f[a][b][c]=max(f[a][b][c],f[a-1][b][c]+v[1][i]);
							if(b>0) f[a][b][c]=max(f[a][b][c],f[a][b-1][c]+v[2][i]);
							if(c>0) f[a][b][c]=max(f[a][b][c],f[a][b][c-1]+v[3][i]);
							ans=max(ans,f[a][b][c]);
							//wr(a),ps,wr(b),ps,wr(c),ps,wr(f[a][b][c]),pn;
						}
					}
				}
			}
			wr(ans),pn;
			memset(f,0,sizeof f);
		}
		
	}
	return 0;
}
//Chtholly bless me!
//If happniess has a color,it must be the blue dyed by the last red!
//What are you doing in the end of the wolrd? Are you busy? Will you save us? 
