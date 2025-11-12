#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int t,n,ans,a[100002][3],d[100002][3][3],f[100002][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t>0)
	{
		memset(d,sizeof(d),0);
		scanf("%d",&n);
		for(int i = 1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);

			for(int j = 0;j<3;j++)
			{
//				printf("%d%d%d",d[i][j][0],d[i][j][1],d[i][j][2]);
				if(i==1){
				f[i][j] = a[i][j];
				d[i][j][j] = 1;
				}
				else{			
					int maxf = max(max(f[i-1][0],f[i-1][1]),f[i-1][2]);
					int max01 = max(f[i-1][0],f[i-1][1]),max12 = max(f[i-1][2],f[i-1][1]),max02 = max(f[i-1][0],f[i-1][2]);
					for(int k=2;k>=0;k--)
					{
						if((d[i-1][k][j]+1)>(n/2)){
							if(k == 0){
							maxf = max12;
							}
							if(k == 1){
							maxf = max02;
							}
							if(k==2) maxf = max01;
						}
					}
					for(int k=2;k>=0;k--){
						int temp=0;			
						if(f[i-1][k] == maxf){
							f[i][j] = a[i][j] + f[i-1][k];
							temp = 1;
						}
						d[i][j][k] = d[i-1][k][j]+temp;
					}
				}
			}
		}
		printf("%d\n",max(max(f[n][0],f[n][1]),f[n][2]));
		t--;
	}
} 
