#include<cstdio>
#include<algorithm>
namespace force{
	int n,m;
	const int MAXN=15;
	const int MAXM=15;
	const int LEN=250;
	int temp[LEN];
	int a[MAXN][MAXM];
	int b[MAXN][MAXM];
	bool cmp(int a,int b){
		return a>b;
	}
	void solve(){
		freopen("seat.in","r",stdin);
		freopen("seat.out","w",stdout);
		scanf("%d%d",&n,&m);
		int len=0;
		int l=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&a[i][j]);
				temp[++len]=a[i][j];
			}
		}
		int k=a[1][1];
		std::sort(&temp[1],&temp[len+1],cmp);
		bool fx=1;
		for(int i=1;i<=n;i++){
			if(fx){
				for(int j=1;j<=m;j++){
					l++;
					if(temp[l]==k) {
						printf("%d %d\n",i,j);
						return;
					}
				}
				fx=0;
			}
			//#Shang4Shan3Ruo6Shui4
			else{
				for(int j=m;j>=1;j--){
					l++;
					if(temp[l]==k){
						printf("%d %d\n",i,j);
						return;
					}
				}
				fx=1;
			}
		}
	}
}
int main(){
	force::solve();
	return 0;
}
