#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],sum1[500001][30],num,cnt,p[30]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=1;j<=21;j++){
			if(a[i]%2==1){
				sum1[i][j]=sum1[i-1][j]+1;
			}else{
				sum1[i][j]=sum1[i-1][j];
			}
			a[i]/=2;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=21;k++){
				if((sum1[j][k]-sum1[i-1][k])%2==1){
					num+=p[k-1];
				}
			}
			if(num==k){
				i=j;
				cnt++;
				num=0;
				break;
			}
			num=0;
		}
	}
	printf("%d",cnt);
	return 0;
}