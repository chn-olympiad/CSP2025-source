#include <bits/stdc++.h>
using namespace std;
int t,n,tu=0,ma;
int a[10009][4],b[10009][2];
int c[4],ans[6],c2[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			c[j]=0;
		}
		for (int j=0;j<n;j++){
			cin>>a[j][0]>>a[j][1]>>a[j][2];
			if(a[j][0]>a[j][1] &&a[j][0]>a[j][2]){
				b[j][0]=0;
				b[j][1]=a[j][0];
				c[0]++;
			}else if(a[j][1]>a[j][0] &&a[j][1]>a[j][2]){
			    b[j][0]=1;
				b[j][1]=a[j][1];
				c[1]++;
			}else{
				b[j][0]=2;
				b[j][1]=a[j][2];
				c[2]++;
			}
		}tu=0;
			for (int i2=0;i2<3;i2++){
				if(!(c[i2]<=n/2)){
					tu=-1;
				}
				
			}
			if(tu==0){
				for (int i3=0;i3<n;i3++){
					ans[i]+=b[i3][1];
				}
			}else if(n==2){
				ma=0;
				for(int k=0;k<3;k++){
					for(int k1=0;k1<3;k1++){
					
						if(k!=k1){
							ma=max(ma,a[0][k]+a[1][k1]);
							
						}
					}
				}
				ans[i]=ma;
			}
				
			}

		
	
	for(int i=0;i<t;i++){
		cout<<ans[i]<<endl;
	}
	
	return 0;
}
	
