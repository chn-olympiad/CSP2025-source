#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int N=1e5+5;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return x*f;
}
struct node{
	int x,id;
	bool operator<(node xx)const{
		return x<xx.x;
	}
}a[N][5];
struct aa{
	int x,y;
}b[N];
int T,n,cnt[5];
inline bool cmp(aa xx,aa yy){
	return xx.x-xx.y<yy.x-yy.y;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++){
			a[i][1].x=read(),a[i][2].x=read(),a[i][3].x=read();
			a[i][1].id=1,a[i][2].id=2,a[i][3].id=3;
			sort(a[i]+1,a[i]+4);
		}
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++)cnt[a[i][3].id]++;
		int ans=0;
		for(int i=1;i<=n;i++)ans+=a[i][3].x;
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
			printf("%lld\n",ans);
			continue;
		}
		int tot=0;
		for(int i=1;i<=n;i++){
			if(cnt[a[i][3].id]>n/2)b[++tot]={a[i][3].x,a[i][2].x};
		}
		sort(b+1,b+tot+1,cmp);
		for(int i=1;i<=tot-n/2;i++)ans+=b[i].y-b[i].x;
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
