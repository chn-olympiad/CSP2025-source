//高跃唐 SN-S00798 西安湖滨中学 
#include<bits/stdc++.h>
using namespace std;
long long int t,n,myd[1001]={};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		long long int a[10001][3],a11=0,ji=0,j111,i111,max11;
		myd[1001]={0};
		cin>>n;
		int b[3]={},m=n;
		bool a1[10001]={0};
		for(int i=0;i<n;i++){for(int j=0;j<3;j++){cin>>a[i][j];}}
		while(m>0){
	    	for(int i=0;i<n;i++){
	    		for(int j=0;j<3;j++){
				        if(a1[i]==1&&i!=n) {
				        	i++;
						}
					if((a[i][j]>max11)&&(b[j]<=(n/2))||(n==2&&(a[i+1][j-1]+a[i][j+1])>a[i][j])){
						max11=a[i][j];
						i111=i;
						j111=j;
					}
				
    	 	}
    	 	b[j111]++;
			a[i111][j111]=0;
    	 	myd[k]+=max11;
			max11=0;
    	 	m--;
    	 	a1[i111]=1;
	 }
}
	}
	for(int i=1;i<=t;i++) {
		cout<<myd[i]<<endl;
	}
	return 0;
}
