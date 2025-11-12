#include<bits/stdc++.h>
using namespace std;
long long t,a[2005][8],n,d[2005]={0},c1=0,c2=0,c3=0,b1,cnt=0,f,h[2005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		f=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			int cc=0;
			for(int z=1;z<=3;z++){
				d[i]=0;
				a[i][b1]=0;
				for(int j=1;j<=3;j++){
					for(int k=1;k<=3;k++){
						if(d[i]<=a[i][k]){
							d[i]=a[i][k];
							h[i]=k;
						}
					}
				}
				if(h[i]==1&&c1++<=f){
					c1++;
					cnt+=d[i];
					break;
				}else if(h[i]==2&&c2++<=f){
					c2++;
				
					cnt+=d[i];
					break;
					}else if(h[i]==3&&c3++<=f){
					c3++;
				
					cnt+=d[i];
					break;
				}else{
					for(int s=1;s<=3;s++){
						if(d[i]==a[i][s]){
							a[i][s]=-1e9;
							d[i]=0;
						}
					}
				}
			}
		}	
		cout<<cnt<<endl;
		cnt=0;
	}
	
	return 0;
} 
