#include<bits/stdc++.h>
using namespace std;
const int NMAX=10005;
long long a[NMAX][4]={0};
long long ans[6]={0};
bool cmpx(int a1,int b1){
	return a[a1][1]>a[b1][1];
}
bool cmpy(int a2,int b2){
	return a[a2][2]>a[b2][2];
}
bool cmpz(int a3,int b3){
	return a[a3][3]>a[b3][3];
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int h=1;h<=T;h++){
		 
		int ax[NMAX]={0},ay[NMAX]={0},az[NMAX]={0};
		int n;
		cin>>n;
		int linx=0,liny=0,linz=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				linx++;
				ax[linx]=i;
			}
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				liny++; 
				ay[liny]=i;
			}
			if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1]){
				linz++;
				az[linz]=i;
			}
		}

		while(linx>n/2||liny>n/2||linz>n/2){
			if(linx>n/2){
				sort(ax+0,ax+linx+1,cmpx);
				for(int i=n/2+1;i<=linx;i++){
					if(a[ax[i]][2]>=a[i][3]){
						ay[liny]=ax[i];
						liny++;
					}
					if(a[ax[i]][3]>=a[i][2]){
						az[linz]=ax[i];
						linz++;
					}
					a[ax[i]][1]=-1;
				}
				linx=n/2;
			}
			if(liny>n/2){
				sort(ay+0,ay+liny+1,cmpy);
					for(int i=n/2+1;i<=liny;i++){
						if(a[ay[i]][1]>=a[i][3]){
							ax[linx]=ay[i];
							linx++;
						}
						if(a[ay[i]][3]>=a[i][1]){
							
							az[linz]=ay[i];
							linz++;
						}
						a[ay[i]][2]=-1;
					}
				liny=n/2;
			}
			if(linz>n/2){
				sort(az+0,az+linz+1,cmpz);
					for(int i=n/2+1;i<=linz;i++){
						
						if(a[az[i]][1]>=a[i][2]){
							ax[linx]=az[i];
							linx++;
						}
						if(a[az[i]][2]>=a[i][1]){
							ay[liny]=az[i];
							liny++;
						}
					a[az[i]][3]=-1;
					}
				linz=n/2;
	  		}
		}

		for(int i=1;i<=linx;i++){
			ans[h]+=a[ax[i]][1];
		}
		for(int i=1;i<=liny;i++){
			ans[h]+=a[ay[i]][2];
		}
		for(int i=1;i<=linz;i++){
			ans[h]+=a[az[i]][3];
		}

	}
	for(int i=1;i<=T;i++){
		cout<<ans[i]<<'\n';
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
