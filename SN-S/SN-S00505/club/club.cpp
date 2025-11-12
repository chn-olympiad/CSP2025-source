#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[10][N][5],b[10][5],c[10][N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		int n;
		scanf("%d",&n);
		int emx=n/2,smx=0,a1=0,a2=0,a3=0;
		for(int j=1;j<=n;j++){
			scanf("%d%d%d",&a[i][j][1],&a[i][j][2],&a[i][j][3]);
			if(a[i][j][1]>a[i][j][2]){
				if(a[i][j][1]>a[i][j][3]){
					b[i][1]++;
					c[i][j]=1;
					a1+=a[i][j][1];
				}else{
					b[i][3]++;
					c[i][j]=3;
					a3+=a[i][j][3];
				}
			}else{
				if(a[i][j][2]>a[i][j][3]){
					b[i][2]++;
					c[i][j]=2;
					a2+=a[i][j][2];
				}else{
					b[i][3]++;
					c[i][j]=3;
					a3+=a[i][j][3];
				}
			}
		}
		smx=a1+a2+a3;
		if(b[i][1]>emx){
			for(int j=1;j<=b[i][1]-emx;j++){
				int mn2=2*10000+10,mn3=mn2,mn=mn3,mnidx2=0,mnidx3=0;
				for(int k=0;k<b[i][1];k++){
					if(a[i][k][1]>a[i][k][2]&&a[i][k][1]-a[i][k][2]<mn2){
						mn2=a[i][k][1]-a[i][k][2];
						mnidx2=k;
					}
					if(a[i][k][1]>a[i][k][3]&&a[i][k][1]-a[i][k][3]<mn3){
						mn3=a[i][k][1]-a[i][k][3];
						mnidx3=k;
					}
				}
				if(mn2<mn3){
					mn=mn2;
					a[i][mnidx2][1]=-1;
				}else if(mn3<mn2){
					mn=mn3;
					a[i][mnidx3][1]=-1;
				}else{
					if(b[i][2]<=b[i][3]){
						mn=mn2;
						a[i][mnidx2][1]=-1;
					}else{
						mn=mn3;
						a[i][mnidx3][1]=-1;
					}
				}
				smx-=mn;
			}
		}
		if(b[i][2]>emx){
			for(int j=1;j<=b[i][2]-emx;j++){
				int mn1=2*10000+10,mn3=mn1,mn=mn3,mnidx1=0,mnidx3=0;
				for(int k=0;k<b[i][2];k++){
					if(a[i][k][2]>a[i][k][1]&&a[i][k][2]-a[i][k][1]<mn1){
						mn1=a[i][k][2]-a[i][k][1];
						mnidx1=k;
					}
					if(a[i][k][2]>a[i][k][3]&&a[i][k][2]-a[i][k][3]<mn3){
						mn3=a[i][k][2]-a[i][k][3];
						mnidx3=k;
					}
				}
				if(mn1<mn3){
					mn=mn1;
					a[i][mnidx1][2]=-1;
				}else if(mn3<mn1){
					mn=mn3;
					a[i][mnidx3][2]=-1;
				}else{
					if(b[i][1]<=b[i][3]){
						mn=mn1;
						a[i][mnidx1][2]=-1;
					}else{
						mn=mn3;
						a[i][mnidx3][2]=-1;
					}
				}
				smx-=mn;
			}
		}
		if(b[i][3]>emx){
			for(int j=1;j<=b[i][3]-emx;j++){
				int mn1=2*10000+10,mn2=mn1,mn=mn2,mnidx1=0,mnidx2=0;
				for(int k=0;k<b[i][3];k++){
					if(a[i][k][3]>a[i][k][1]&&a[i][k][3]-a[i][k][1]<mn1){
						mn1=a[i][k][3]-a[i][k][1];
						mnidx1=k;
					}
					if(a[i][k][3]>a[i][k][2]&&a[i][k][3]-a[i][k][2]<mn2){
						mn2=a[i][k][3]-a[i][k][2];
						mnidx2=k;
					}
				}
				if(mn1<mn2){
					mn=mn1;
					a[i][mnidx1][3]=-1;
				}else if(mn2<mn1){
					mn=mn2;
					a[i][mnidx2][3]=-1;
				}else{
					if(b[i][1]<=b[i][2]){
						mn=mn1;
						a[i][mnidx1][3]=-1;
					}else{
						mn=mn2;
						a[i][mnidx2][3]=-1;
					}
				}
				smx-=mn;
			}
		}
		cout<<smx<<endl;
	}
	return 0;
}
