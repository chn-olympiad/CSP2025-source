#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int z=1;z<=t;z++){
		int n;
		long long sum=0;
		cin>>n;
		int a[60005][6]={0},d[4]={0};
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];			
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				a[i][4]=a[i][1];
				a[i][5]=a[i][1]-max(a[i][2],a[i][3]);
				a[i][6]=1;
				d[1]++; 
			}
			else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
				a[i][4]=a[i][2];
				a[i][5]=a[i][2]-max(a[i][1],a[i][3]);
				a[i][6]=2;
				d[2]++; 
			}
			else if(a[i][3]>a[i][1]&&a[i][2]<a[i][3]){
				a[i][4]=a[i][3];
				a[i][5]=a[i][3]-max(a[i][2],a[i][1]);
				a[i][6]=3;
				d[3]++; 
			}
			else if(a[i][3]==a[i][2]&&a[i][1]==a[i][3]){
				sum+=a[i][3];
				a[i][5]=100000;
			}
			else if(a[i][3]==a[i][2]&&a[i][3]!=a[i][1]){
				if(a[i][1]>a[i][3]){
					a[i][4]=a[i][1];
					a[i][5]=a[i][1]-a[i][2];
					a[i][6]=1;
					d[1]++; 
				}
				else{
					a[i][4]=a[i][3];
					a[i][5]=0;
					a[i][6]=3;
					d[3]++; 
				}
			}
			else if(a[i][1]==a[i][2]&&a[i][3]!=a[i][1]){
				if(a[i][1]>a[i][3]){
					a[i][4]=a[i][1];
					a[i][5]=0;
					a[i][6]=1;
					d[1]++; 
				}
				else{
					a[i][4]=a[i][3];
					a[i][5]=a[i][3]-a[i][1];
					a[i][6]=3;
					d[3]++; 
				}
			}
			else if(a[i][3]==a[i][1]&&a[i][3]!=a[i][2]){
				if(a[i][1]>a[i][2]){
					a[i][4]=a[i][1];
					a[i][5]=0;
					a[i][6]=1;
					d[1]++; 
				}
				else{
					a[i][4]=a[i][2];
					a[i][5]=a[i][2]-a[i][1];
					a[i][6]=2;
					d[2]++; 
				}
			}
		}
		for(int i=1;i<=n;i++){
			sum+=a[i][4];
		}
		cout<<d[1]<<" "<<d[2]<<" "<<d[3]<<endl;
		if((d[1]<=n/2&&d[2]<=n/2)&&d[3]<=n/2){
			cout<<sum<<endl;
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[i][5]>a[j][5]){
						swap(a[i][5],a[j][5]);
					}
				}
			}
			int maxnn=max(d[1],d[2]);
			maxnn=max(maxnn,d[3]);
			for(int i=1;i<=maxnn-n/2;i++){
				sum-=a[i][5];
			}
			cout<<sum<<endl;			
		}
	}
	return 0;
} 
