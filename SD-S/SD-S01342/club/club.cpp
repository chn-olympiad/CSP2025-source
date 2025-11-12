#include<bits/stdc++.h>
using namespace std;
int t,n,sum=0,js[3]={0};
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;	
	while(t!=0){
		cin>>n;
		long int k=n/2;
//		int a[n][3];
//		for(int i=0;i<n;i++)
//			for(int j=0;j<3;j++)
//				cin>>a[i][j];
//		for(int i=0;i<n;i++){
//			if(a[i][0]==0 or a[i][1]==0 or a[i][2]==0){
//				
//			}
//		}
		for(int i=0;i<n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			long int max[2]={0},zh[2]={0},min[2]={0};	max[0]=x;	max[1]=0;
			if(y>=x){
				max[0]=y;
				max[1]=1;}
			else if(z>=x){
				max[0]=z;
				max[1]=2;}
			if(max[1]==0){
				if(y>z){
					zh[0]=y;	zh[1]=1;
					min[0]=z;	min[1]=2;
				}
				else{
					zh[0]=z;	zh[1]=2;
					min[0]=y;	min[1]=1;
				}
			}
			if(max[1]==1){
				if(x>z){
					zh[0]=x;	zh[1]=0;
					min[0]=z;	min[1]=2;
				}
				else{
					zh[0]=z;	zh[1]=2;
					min[0]=x;	min[1]=0;
				}
			}
			if(max[1]==2){
				if(y>x){
					zh[0]=y;	zh[1]=1;
					min[0]=x;	min[1]=0;
				}
				else{
					zh[0]=x;	zh[1]=0;
					min[0]=y;	min[1]=1;
				}
			}
			if(js[max[1]]<k){
				js[max[1]]++;
				sum+=max[0];
			}
			else if(js[max[1]]>=k and js[zh[1]]<k){
				js[zh[1]]++;
				sum+=zh[0];
			}
			else if(js[max[1]]>=k and js[zh[1]]>=k and js[min[1]]<k){
				js[min[1]]++;
				sum+=min[0];
			}
			else{
				continue;
			}
		}
		t--;
		cout<<sum<<endl;	sum=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
