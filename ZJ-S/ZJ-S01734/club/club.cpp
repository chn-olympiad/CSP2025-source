#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][4],b[100010][4],sum1,sum2;
int d[100010];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				sum1+=a[i][2];
				sum2+=a[i][3];
			}
		}
		if(n==2){
			d[1]=a[1][1]+max(a[2][2],a[2][3]);
			d[2]=a[1][2]+max(a[2][1],a[2][3]);
			d[3]=a[1][3]+max(a[2][1],a[2][2]);
			cout<<max(d[1],max(d[2],d[3]));	
		}
		else if(sum1==0){
			if(sum2==0){
				for(int i=1;i<=n;i++){
					d[i]=a[i][1];
				}
				sort(d+1,d+1+n);
				sum1=0;
				for(int i=n;i>n/2;i--){
					sum1+=d[i];
				}
				cout<<sum1;
			}
			else{
				continue;
			}
		}
		cout<<endl;	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
