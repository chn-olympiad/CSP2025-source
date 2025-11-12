#include<bits/stdc++.h>
using namespace std;

int t,n;
int a[4][300000];
int x,y,z; 
int d[300000];
int sum;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int j=1;j<=t;j++){
		n=0,x=0,y=0,z=0,sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[1][i],&a[2][i],&a[3][i]);
			int v=0;
			if(a[1][i]>a[2][i]&&a[1][i]>a[3][i]){
				x++;
				int ma=max(a[2][i],a[3][i]);
				if(a[2][i]==a[3][i])ma=a[2][i];
				d[i]=a[1][i]-ma;
				sum+=a[1][i];
			}			
			if(a[2][i]>a[1][i]&&a[2][i]>a[3][i]){
				y++;
				int ma=max(a[1][i],a[3][i]);
				if(a[1][i]==a[3][i])ma=a[1][i];
				d[i]=a[2][i]-ma;
				sum+=a[2][i];
			}			
			if(a[3][i]>a[2][i]&&a[3][i]>a[1][i]){
				z++;
				int ma=max(a[1][i],a[2][i]);
				if(a[1][i]==a[2][i])ma=a[1][i];
				d[i]=a[3][i]-ma;
				sum+=a[3][i];
			}					
			
		}
		if(x>n/2){
			for(int u=1;u<=x-n/2;u++){
				int mi=0x3f,l;
				for(int i=1;i<=n;i++){	
					if(mi>d[i]){
						l=i;
						mi=d[i];
					}
				}
				sum-=d[l];
				d[l]=0x3f;
				
			}
		}
		if(y>n/2){
			for(int u=1;u<=y-n/2;u++){
				int mi=0x3f,l;
				for(int i=1;i<=n;i++){	
					if(mi>d[i]){
						l=i;
						mi=d[i];
					}
				}
				sum-=d[l];
				d[l]=0x3f;
				
			}
		}
		if(z>n/2){
			for(int u=1;u<=z-n/2;u++){
				int mi=0x3f,l;
				for(int i=1;i<=n;i++){	
					if(mi>d[i]){
						l=i;
						mi=d[i];
					}
				}
				sum-=d[l];
				d[l]=0x3f;
				
			}
		}
		printf("%d",sum);
	}
	return 0;
} 





