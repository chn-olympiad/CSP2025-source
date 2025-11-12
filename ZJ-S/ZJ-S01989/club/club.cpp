#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define L(i,a,b) for(int i=(a);i<=(b);i++)
#define R(i,a,b) for(int i=(a);i>=(b);i--)
#define ttop aijodsjlasd
#define mymain iadsjkjifes
#define k1 aodskkasdl
#define mycmp adsijoasiofj
using namespace std;
const int Mxn=1e5+10;
int T;
int n,m;
int a[5][Mxn];
int b[Mxn];//B：第i个人在的社团(123)
int d[5][Mxn],ttop[5];//第i社团的人ID 第i社团人数
long long ans=0;
struct E{
	int id;
	int s,to;
}p,q[Mxn];
int qtop=0;
bool mycmp(E x,E y){
	return x.s<y.s;
}
int ti,tx;
void mymain() {
	ans=0;qtop=0;
	memset(ttop,0,sizeof(ttop));
	//先全部选最大值 超出的部分找到换成别的组损失小的
	scanf("%d",&n);
	L(i,1,n) {
		ti=0,tx=-1e9;
		L(k,1,3) { //确定最大值
			scanf("%d",&a[k][i]);
			if(a[k][i]>=tx)tx=a[k][i],ti=k;
		}
		b[i]=ti;
		d[ti][++ttop[ti]]=i;
	}
	L(k,1,3)if(ttop[k]>n/2) {//超出部分处理 
		m=ttop[k]-(n/2);
		int i;
		L(j,1,ttop[k]) {
			i=d[k][j];
			ti=0,tx=1e9;
			L(k1,1,3) {//找到代替的值 
				if(k1==k)continue;
				if(a[k][i]-a[k1][i]<tx)tx=a[k][i]-a[k1][i],ti=k1;
			}
			q[++qtop].id=i;
			q[qtop].s=tx;
			q[qtop].to=ti;
		}
		sort(q+1,q+ttop[k]+1,mycmp);
		L(j,1,m){//替换b内 
			i=q[j].id;
			b[i]=q[j].to;
		} 
		break;
	}
	L(i,1,n)ans+=a[b[i]][i];//计算ans
	printf("%lld\n",ans);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)mymain();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
