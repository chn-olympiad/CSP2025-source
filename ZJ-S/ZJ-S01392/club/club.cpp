#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long s,b[4][200000];
int n,T,i,j,x,f[4],y;
struct node{ll x,id;}a[200000][4];
bool cmp(const node&x,const node&y){return x.x>y.x;}
void read(long long &x){
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	x=0;
	while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		f[1]=f[2]=f[3]=s=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=3;j++)
				read(a[i][j].x),a[i][j].id=j;
			sort(a[i]+1,a[i]+4,cmp);
			s+=a[i][1].x;f[a[i][1].id]++;
			b[a[i][1].id][f[a[i][1].id]]=a[i][1].x-a[i][2].x;
		}
//		printf("\n%d\n%d %d %d\n",s,f[1],f[2],f[3]);
		sort(b[1]+1,b[1]+f[1]+1);
		sort(b[2]+1,b[2]+f[2]+1);
		sort(b[3]+1,b[3]+f[3]+1);
//		for(i=1;i<=n;i++)printf("%d ",b[i]);
//		putchar(10);
		y=0;
		if(f[1]>n/2)y=1,x=f[1];
		else if(f[2]>n/2)y=2,x=f[2];
		else if(f[3]>n/2)y=3,x=f[3];
		if(y)for(i=1;i<=x-n/2;i++)s-=b[y][i];
		printf("%lld\n",s);
	}
	return 0;
}
