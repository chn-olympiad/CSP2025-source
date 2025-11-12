//RP++ 300+ Please!
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=5e5+5,maxm=1.5e7+5;
int n,m,s,ans,a[maxn],sum[maxn][25][2],vis[maxm];
struct node{
	int l,r,len;
	bool operator<(const node &B)const{return len<B.len;}
}p[maxn];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=(ret<<1)+(ret<<3)+(ch&15),ch=getchar();
	return ret*f;
}
bool check(int x,int y){
	for(int j=1;j<=20;j++){
		int now1=sum[y][j][1]-sum[x-1][j][1],now2=sum[y][j][0]-sum[x-1][j][0];
		if((m>>(j-1))&1)now1++;
		else now2++;
		if(now1%2!=0||now2%2!=0)return 0;
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),m=read();bool k=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]!=1)k=1;
	}
	if(k){
		for(int i=1;i<=n;i++)for(int j=20;j;j--)sum[i][j][1]=sum[i-1][j][1]+((a[i]>>(j-1))&1),sum[i][j][0]=i-sum[i][j][1];
		for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)if(check(i,j))p[++s]=(node){i,j,j-i+1};
		sort(1+p,1+p+s);
		for(int i=1;i<=s;i++){
			bool k=1;
			for(int j=p[i].l;j<=p[i].r;j++)if(vis[j]){k=0;break;}
			if(k){
				ans++;
				for(int j=p[i].l;j<=p[i].r;j++)vis[j]=1;
			}
		}
		printf("%d\n",ans);
	}
	else{
		printf("%d\n",n/2);
	}
	return 0;
}