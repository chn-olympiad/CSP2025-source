#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum;
int T,n,a[100006][5],k1,k2,k3,cha[100006];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(cha,0x3f,sizeof(cha));
		sum=0;
		k1=0;
		k2=0;
		k3=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			sum=sum+max(a[i][1],max(a[i][2],a[i][3]));
			if((a[i][1]>=a[i][2])&&(a[i][1]>=a[i][3])){
				k1++;
			}
			else if((a[i][2]>=a[i][1])&&(a[i][2]>=a[i][3])){
				k2++;
			}
			else if((a[i][3]>=a[i][1])&&(a[i][3]>=a[i][2])){
				k3++;
			}
		}
		if(k1>n/2){
			for(int i=1;i<=n;i++){
				if((a[i][1]>=a[i][2])&&(a[i][1]>=a[i][3])){
					cha[i]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
				}
			}
			sort(cha+1,cha+1+n);
			for(int i=1;i<=n;i++){
				if(k1>n/2){
					sum-=cha[i];
					k1--;
				}
				else break;
			}
		}
		else if(k2>n/2){
			for(int i=1;i<=n;i++){
				if((a[i][2]>=a[i][1])&&(a[i][2]>=a[i][3])){
					cha[i]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
				}
			}
			sort(cha+1,cha+1+n);
			for(int i=1;i<=n;i++){
					if(k2>n/2){	
						sum-=cha[i];
						k2--;
					}
					else break;
				}
			}
		else if(k3>n/2){
			for(int i=1;i<=n;i++){
				if((a[i][3]>=a[i][1])&&(a[i][3]>=a[i][2])){
					cha[i]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
				}
			}
			sort(cha+1,cha+1+n);
			for(int i=1;i<=n;i++){
				if(k3>n/2){
					sum-=cha[i];
					k3--;
				}
			}
		}
		
		printf("%lld\n",sum);
	}
	
	return 0;
}
