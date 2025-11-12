#include<bits/stdc++.h>
#define int long long
#define fast register int
using namespace std;
const int maxn=1e5+5;

struct node{
	int a[4];
	int ma;
	int c;
}s[maxn];

int n,k,T,sum[4],ans,ma;
bool flag;

bool cmp(node x,node y){
	return x.c>y.c;
}

inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}

inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar('0'+x%10);
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		for(fast i=1;i<=n;i++){
			s[i].a[1]=read(),s[i].a[2]=read(),s[i].a[3]=read();
			int x=1,y=1;
			for(fast j=2;j<=3;j++){
				if(s[i].a[j]>s[i].a[x]){
					x=j;
				}
				if(s[i].a[j]<s[i].a[y]){
					y=j;
				}
			}
			s[i].ma=x;
			for(fast j=1;j<=3;j++){
				if(j!=x&&j!=y){
					s[i].c=s[i].a[s[i].ma]-s[i].a[j];
					break;
				}
			}
		}
		sort(s+1,s+n+1,cmp);
		flag=false;
		memset(sum,0,sizeof(sum));
		ans=0;
		for(fast i=1;i<=n;i++){
			if(flag==false){
				ans+=s[i].a[s[i].ma];
				sum[s[i].ma]++;
				if(sum[s[i].ma]>=n/2){
					flag=true;
					ma=s[i].ma;
				}
			}else{
				int m=-1;
				for(fast j=1;j<=3;j++){
					if(j!=ma){
						m=max(s[i].a[j],m);
					}
				}
				ans+=m;
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}