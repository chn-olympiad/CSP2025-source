#include <bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();
	int x=0,f=1;
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+c-48,c=getchar();
	return x*f;
}
inline void print(const int x){
	if(x==0){putchar('0');return;}
	int t=x;
	if(t<0)t=-t,putchar('-');
	int num[40],len=0;
	while(t)num[len++]=t%10+48,t/=10;
	while(len--)putchar(num[len]);
}
const int N=1e5+5;

int a[N][3];
bool flag[N];
struct node{
	int x,id,c;
	bool operator<(const node& t)const{
		return t.x>x;
	}
}b[N<<2];
int f[2][205][205][205];

inline void solve(){
	int n=read();
	int ans=0;
	for(int i=1;i<=n;i++)
	for(int j=0;j<3;j++)a[i][j]=read();
	if(n<=200){
		memset(f,0,2*205*205*205*sizeof(int));
		for(int i=1;i<=n;i++){
			for(int j=0;j<=i;j++){
				if(j>n/2)break;
				for(int k=i-j;~k;k--){
					int l=i-j-k;
					if(l>n/2)break;
					if(k>n/2)continue;
					if(j>0)f[i&1][j][k][l]=max(f[i&1][j][k][l],f[(i&1)^1][j-1][k][l]+a[i][0]);
					if(k>0)f[i&1][j][k][l]=max(f[i&1][j][k][l],f[(i&1)^1][j][k-1][l]+a[i][1]);
					if(l>0)f[i&1][j][k][l]=max(f[i&1][j][k][l],f[(i&1)^1][j][k][l-1]+a[i][2]);
				}
			}
			memset(f[(i&1)^1],0,205*205*205*sizeof(int));
		}
		int ans=0;
		for(int j=0;j<=n/2;j++)
		for(int k=0;k<=n/2&&j+k<=n;k++)if(j+k>=n/2)ans=max(ans,f[n&1][j][k][n-j-k]);
		print(ans),putchar('\n');
		return;
	}
	priority_queue<node> q;
	int cnt[3];
	cnt[0]=cnt[1]=cnt[2]=0;
	for(int i=1;i<=n;i++)flag[i]=0;
	int m=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++)b[++m]=node{a[i][j],i,j};
	sort(b+1,b+m+1);
	int sum=0;
	while(m){
		node t=b[m--];
		if(flag[t.id]||cnt[t.c]+1>n/2)continue;
		sum+=t.x,flag[t.id]=1,++cnt[t.c];
	}
	ans=max(ans,sum);
	for(int t=0;t<30;t++){
		cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1;i<=n;i++)flag[i]=0;
		m=0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++)b[++m]=node{a[i][j],i,j};
		sort(b+1,b+m+1);
		sum=0;
		while(m){
			node t=b[m--];
			if(flag[t.id]||cnt[t.c]+1>n/2)continue;
			if((rand()&8)>5)continue;
			sum+=t.x,flag[t.id]=1,++cnt[t.c];
		}
		ans=max(ans,sum);
	}
	for(int t=0;t<30;t++){
		cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1;i<=n;i++)flag[i]=0;
		m=0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++)b[++m]=node{a[i][j],i,j};
		sort(b+1,b+m+1);
		sum=0;
		while(m){
			node t=b[m--];
			if(flag[t.id]||cnt[t.c]+1>n/2)continue;
			if((rand()&8)<=5)continue;
			sum+=t.x,flag[t.id]=1,++cnt[t.c];
		}
		ans=max(ans,sum);
	}
	print(ans),putchar('\n');
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	srand(time(NULL));
	int t=read();
	while(t--)solve();
	return 0;
}
