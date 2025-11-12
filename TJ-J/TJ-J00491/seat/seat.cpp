#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<string>
int n,m;
const int maxn=30,maxm=30,maxS=500;
struct item{
	int v,id;
	friend bool operator <(item x,item y){
		return x.v>y.v;
	}
}a[maxn],mp[maxn][maxm];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i].v),a[i].id=i;
	std::sort(a+1,a+n*m+1);
	int len=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++) mp[i%2==0?n-j+1:j][i]=a[++len];
	int x=0,y=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) if(mp[i][j].id==1) x=i,y=j;
	printf("%d %d\n",y,x);
	return 0;
}
