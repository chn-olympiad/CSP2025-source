#include<iostream>
#include<cmath>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,i,num=0;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>n;
		int a[n][3]={0},p[n][3]={0},r[3]={0,0,0},x[n][3]={0},z[3][n]={0},sum=0,f[n]={0};
		int a1;
		for(int j=0;j<n;j++){
			cin>>a[j][0]>>a[j][1]>>a[j][2];
			p[j][0]=max(a[j][0],max(a[j][1],a[j][2]));
			p[j][2]=min(a[j][0],min(a[j][1],a[j][2]));
			p[j][1]=a[j][0]+a[j][1]+a[j][2]-p[j][0]-p[j][2];
			x[j][0]=a[j][0]-a[j][1];
			x[j][2]=a[j][0]-a[j][2];
			x[j][1]=a[j][1]-a[j][2];
			if(p[j][0]==a[j][0]){
				r[0]++;
				f[j]=0;
			}else if(p[j][0]==a[j][1]){
				r[1]++;
				f[j]=1;
			}else{
				r[2]++;
				f[j]=2;
			}
		}
		for(int m=0;m<n;m++){
			int e=120000;
			for(int k=0;k<n;k++){
				if(e>x[k][1]){
					e=x[k][1];
					z[1][m]=k;
				}
			}
		}
		for(int m=0;m<n;m++){
			int e=50000;
			for(int k=0;k<n;k++){
				if(e>x[k][0]){
					e=x[k][0];
					z[0][m]=k;
				}
			}
		}
		for(int m=0;m<n;m++){
			int e=50000;
			for(int k=0;k<n;k++){
				if(e>x[k][2]){
					e=x[k][2];
					z[2][m]=k;
				}
			}
		}
		while(r[0]>n/2||r[1]>n/2||r[2]>n/2){
			if(r[0]>n/2){
				num=r[0]-n/2;
				r[0]-=num;
				for(int k=0;k<num;k++){
					if(a[z[0][k]][1]<=a[z[0][k]][2]){
						r[2]++;
						f[k]=2;
					}else{
						r[1]++;
						f[k]=1;
					}
				}
			}else if(r[1]>n/2){
				num=r[1]-n/2;
				r[1]-=num;
				for(int k=0;k<num;k++){
					if(a[z[2][k]][0]<=a[z[2][k]][2]){
						r[2]++;
						f[k]=2;
					}else{
						r[0]++;
						f[k]=0;
					}
				}
			}else if(r[2]>n/2){
				num=r[2]-n/2;
				r[2]-=num;
				for(int k=0;k<num;k++){
					if(a[z[1][k]][0]>=a[z[1][k]][1]){
						r[1]++;
						f[k]=1;
					}else{
						r[0]++;
						f[k]=0;
					}
				}
			}	
		}
		for(int j=0;j<n;j++){
			sum+=a[j][f[j]];
		}
		cout<<sum<<endl;
	}
	return 0;
}
