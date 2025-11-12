#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("club.in",'w',stdin);
//	freopen("club.out",'r',stdout);
	int n,t,trmp,sum=0;
	cin>>t;
	for(int x=1;x<=t;x++){
		cin>>n;
		int a[n][3]={0};
		for (int y=0;y<n;y++){
			for (int i=0;i<=2;i++){
				cin>>a[y][i];
			}
	    }
		for (int i=1;i<=n;i++){
			for (int j=i-1;j<=n-1;j++){
				if (a[i][0]>a[j][0]){
					trmp=a[i][0];
					a[i][0]=a[j][0];
					a[j][0]=trmp;
				}
			}
		}
		for (int i=0;i<=n/2;i++){
			sum+=a[i][0];
			a[i][0]=0;
			a[i][1]=0;
			a[i][2]=0;
		}
		
		for (int i=1;i<=n;i++){
			for (int j=i-1;j<=n-1;j++){
				if (a[i][1]>a[j][1]){
					trmp=a[i][1];
					a[i][1]=a[j][1];
					a[j][1]=trmp;
				}
			}
		}
		for (int i=0;i<=n/2+(n/2)/2;i++){
			sum+=a[i][1];
			a[i][0]=0;
			a[i][1]=0;
			a[i][2]=0;
		}
		
		for (int i=1;i<=n;i++){
			for (int j=i-1;j<=n-1;j++){
				if (a[i][2]>a[j][2]){
					trmp=a[i][2];
					a[i][2]=a[j][2];
					a[j][2]=trmp;
				}
			}
		}
		for (int i=0;i<=n;i++){
			sum+=a[i][2];
			a[i][0]=0;
			a[i][1]=0;
			a[i][2]=0;
		}
		
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}
