#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar('0'+x%10);
}
const int N=1e5+5;
int t,n,a[N][4],b[4][N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		int s=0,t1=0,t2=0,t3=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j)a[i][j]=read();
			int mx=max(max(a[i][1],a[i][2]),a[i][3]);
			s+=mx;
			int dif1=mx-a[i][1],dif2=mx-a[i][2],dif3=mx-a[i][3];
			if(a[i][1]==mx){
				++t1;
				b[1][t1]=min(dif2,dif3);
			}
			else if(a[i][2]==mx){
				++t2;
				b[2][t2]=min(dif1,dif3);
			}
			else if(a[i][3]==mx){
				++t3;
				b[3][t3]=min(dif1,dif2);
			}
		}
		if(t1>n/2){
			sort(b[1]+1,b[1]+t1+1);
			for(int i=1;i<=t1-n/2;++i)s-=b[1][i];
		}
		if(t2>n/2){
			sort(b[2]+1,b[2]+t2+1);
			for(int i=1;i<=t2-n/2;++i)s-=b[2][i];
		}
		if(t3>n/2){
			sort(b[3]+1,b[3]+t3+1);
			for(int i=1;i<=t3-n/2;++i)s-=b[3][i];
		}
		write(s);
		putchar('\n');
	}
	return 0;
}