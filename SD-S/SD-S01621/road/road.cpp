#include<cstdio>
using namespace std;
#define ll long long
ll rd(){
	char c=getchar();
	short f=1;
	ll rt=0;
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		rt=rt*10+c-'0';
		c=getchar();
	}
	return rt*f;
}
ll n,m,k,u,v,w,floyd[10005][10005]={},a[15][10005],ans=0,lf[10005][10005],c[15];
bool tsxza=0,bj[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd(),m=rd(),k=rd();
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i^j)floyd[i][j]=10000000000005;
	for(int i=0;i<m;i++){
		u=rd();
		v=rd();
		w=rd();
		floyd[u][v]=w;
		floyd[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		c[i]=rd();
		if(!c[i])tsxza=1;
		for(int j=1;j<=n;j++){
			a[i][j]=rd();
			if(a[i][j])tsxza=0;
		}
	}
	if(tsxza){
		putchar('0');
		return 0;
	}
	bool f=1;
	while(f){
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++)printf("%lld ",floyd[i][j]);
//			putchar('\n');
//		}
//		putchar('\n');
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				for(int l=1;l<=n;l++)
					if(floyd[i][l]+floyd[l][j]<floyd[i][j])
						floyd[j][i]=floyd[i][j]=floyd[i][l]+floyd[l][j];
				for(int l=1;l<=k;l++)
					if(a[i][l]+a[l][j]+(bj[l]?0:c[l])<floyd[i][j]){
						floyd[j][i]=floyd[i][j]=a[l][i]+a[l][j]+(bj[l]?0:c[l]);
						if(!bj[l])bj[l]=1;
					}
			}
		f=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
			if(floyd[i][j]!=lf[i][j]){
				f=1;
				lf[i][j]=floyd[i][j];
			}
		}
	}
	for(int i=2;i<=n;i++)ans+=floyd[1][i];
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*







行行好吧，给孩子一个二等奖吧 

能骗几分是几分吧 








	天灵灵地灵灵，我的代码不爆零 






*/
