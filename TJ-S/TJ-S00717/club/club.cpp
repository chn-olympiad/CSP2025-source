#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a[100000][5];
	int sum[10000];
	int ans,s1=0,s2=0,s3=0,max_hhh=0;
	int n=0,t=0;
	
	cin>>n;
	for(int w=1;w<=n;w++){
		cin>>t;
		sum[n]=0;
		s1=0,s2=0,s3=0;
		for(int i=1;i<=t;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			
		}
		/*for(int i=1;i<=t;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int a1=1;a1<=n;a1++){
			if(a[a1]>max1_hhh) max1_hhh=a[a1];
		}
		for(int a1=1;a1<=n;a1++){
			if(b[a1]>max2_hhh) max2_hhh=b[a1];
		}
		for(int a1=1;a1<=n;a1++){
			if(c[a1]>max3_hhh) max3_hhh=c[a1];
		}*/
		for(int i=1;i<=t;i++){
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]&&s1<=n/2){
					s1++;
					sum[w]+=a[i][1];
					//cout<<" "<<"ws1hhh";
				
			}
			else if(a[i][2]>a[i][3]&&a[i][2]>a[i][1]&&s2<=n/2){
				s2++;
				sum[w]+=a[i][2];
				//cout<<" "<<"ws2hhh";
			}
			else{
				s3++;
				sum[w]+=a[i][3];
				//cout<<" "<<"ws3hhh";
			}
		}
	}
	for(int qqq=1;qqq<=n;qqq++){
		cout<<sum[qqq]<<endl;
	}
	return 0;
}
