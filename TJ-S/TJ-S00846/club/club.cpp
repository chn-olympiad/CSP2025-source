#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int A[100010];
int b0[100010];
int b1[100010];
int a[100010][5];
int sum;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}	
		}
		int total3=0;
		int total0;
		int total1;
		int total;
		int flag;
		for(int i=0;i<n;i++){
			if(a[i][1]==a[i][2]&&a[i][1]==0&&a[i][2]==0){
				flag=1;	
				A[i]=a[i][0];
			}if(a[i][2]==0&&a[i][0]!=0&&a[i][1]!=0){
				flag=2;
				b0[i]=a[i][0];
				b1[i]=a[i][1];
			}
		}
		if(flag==1){
		sort(A,A+n,cmp);
			for(int i=0;i<n/2;i++){
				total3+=A[i];	
			}cout<<total3<<endl;
		}else if(flag==2){
			sort(b0,b0+n,cmp);
			sort(b1,b1+n,cmp);
			for(int i=0;i<n/2;i++){
				for(int j=n/2;j<n;j++){
					total0+=a[i][0];
					total0+=a[j][1];
					total1+=a[i][1];
					total1+=a[j][0];
					if(total0<total1){
						total=total1/2;
					}else{
						total=total0/2;
					}
				}
			}cout<<total<<endl;
		}
	}
	return 0;
}

