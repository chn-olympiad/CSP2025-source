#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int n,a[100005][4],b[100005],c[4];
		c[1]=0,c[2]=0,c[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)cin>>a[i][j];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])c[1]++,b[i]=1;
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])c[2]++,b[i]=2;
			if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])c[3]++,b[i]=3;
		}
		for(int i=1;i<=n;i++){
			if(c[1]>n/2){
				int xb,fw,w=0,cha;
				for(int q=1;q<=n;q++){
					if(b[q]==1){
						int ss=max(a[q][2],a[q][3]);
						w++;
						if(w==1){
							cha=a[q][1]-ss,xb=q;
							if(ss==a[q][2])fw=2;
							else fw=3;
						}
						else{
							if(a[q][1]-ss<cha){
								cha=a[q][1]-ss;
								xb=q;
								if(ss==a[q][2])fw=2;
								else fw=3;
							}
						}
						
					}
				}
				c[1]--,c[fw]++,b[xb]=fw;
			}
			if(c[2]>n/2){
				int xb,fw,w=0,cha;
				for(int q=1;q<=n;q++){
					if(b[q]==2){
						int ss=max(a[q][1],a[q][3]);
						w++;
						if(w==1){
							cha=a[q][2]-ss,xb=q;
							if(ss==a[q][1])fw=1;
							else fw=3;
						}
						else{
							if(a[q][2]-ss<cha){
								cha=a[q][2]-ss;
								xb=q;
								if(ss==a[q][1])fw=1;
								else fw=3;
							}
						}
						
					}
				}
				c[2]--,c[fw]++,b[xb]=fw;
			}
			if(c[3]>n/2){
				int xb,fw,w=0,cha;
				for(int q=1;q<=n;q++){
					if(b[q]==3){
						int ss=max(a[q][2],a[q][1]);
						w++;
						if(w==1){
							cha=a[q][3]-ss,xb=q;
							if(ss==a[q][2])fw=2;
							else fw=1;
						}
						else{
							if(a[q][3]-ss<cha){
								cha=a[q][3]-ss;
								xb=q;
								if(ss==a[q][2])fw=2;
								else fw=1;
							}
						}
						
					}
				}
				c[3]--,c[fw]++,b[xb]=fw;
			}
		} 
		int k=0;
		for(int i=1;i<=n;i++)k+=a[i][b[i]];
		cout<<k<<endl;
	}
	return 0;
} 
