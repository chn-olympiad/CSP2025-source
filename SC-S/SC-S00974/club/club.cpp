#include<bits/stdc++.h>
using namespace std;
int const N=2e5+5;
int t;
int n,a[N][4],maxi;
int cnt[4],maxn,d[N][4],minn,md[N],x[N][4];
bool f;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		cnt[1]=0;cnt[2]=0;cnt[3]=0;maxn=0;
		for(int i=1;i<=n;i++){
		    maxi=-1;
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
				maxi=max(maxi,a[i][j]);
				x[i][j]=0;
			}
			maxn+=maxi;f=0;
		    for(int j=1;j<=3;j++){
				if(maxi==a[i][j]&&f==0){
					cnt[j]++;f=1;
					x[i][j]=1;
				}
				d[i][j]=maxi-a[i][j];
			}
//			printf("%d %d %d %d\n",cnt[1],cnt[2],cnt[3],maxi);
		}
		
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
			printf("%d\n",maxn);
		}
		else{
			if(cnt[2]>n/2){
				swap(cnt[1],cnt[2]);
				for(int i=1;i<=n;i++){
					swap(d[i][1],d[i][2]);
					swap(x[i][1],x[i][2]);
				}
			}
			if(cnt[3]>n/2){
				swap(cnt[1],cnt[3]);
				for(int i=1;i<=n;i++){
					swap(d[i][1],d[i][3]);
					swap(x[i][1],x[i][3]);
				}
			}
			minn=0;
			for(int i=1;i<=n;i++){
				if(x[i][1]==1) md[i]=min(d[i][2],d[i][3]);
				else md[i]=N;
			}
			sort(md+1,md+1+n);
			for(int i=1;i<=cnt[1]-n/2;i++){
				minn+=md[i];
			}
			printf("%d\n",maxn-minn);
		}
	}
	return 0;
}