#include <cstdio>
namespace h{
	const int maxn=100+4;
	int a[maxn];
	int c[maxn];
	void solve(){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n*m;i++)
			scanf("%d",&a[i]);
		int h=a[1];
		for(int i=1;i<=n*m;i++){
			for(int j=i+1;j<=n*m;j++){
				if(a[j]>a[i]){
					int t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
			}	
		}
		int i=0,j=0;
		for(int u=1;u<=n*m;u++){
			if(a[u]==h){
				i=(u+n-1)/n;
				j=u/n+1;
				break;
			}
		}
		
		printf("%d %d\n",i,j);
		return;
	}
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	h::solve();
	return 0;
}
