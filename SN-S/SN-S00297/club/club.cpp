//施懿洋 SN-S00297 西安铁一中滨河高级中学
#include<bits/stdc++.h>
using namespace std;
int t,n,a[5],d[5],z[5],q[10],ans,cho1,cho2,cho3,num;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		num=n/2;
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
			cin>>a[l];
			}
			if(a[1]>=a[2]>=a[3]){
				d[j]=a[1];
				z[j]=a[2];
				cho1++;
			}
			if(a[1]>=a[3]>=a[2]){
				d[j]=a[1];
				z[j]=a[3];
				cho1++;
			}
			if(a[2]>=a[1]>=a[3]){
				d[j]=a[2];
				z[j]=a[1];
				cho2++;
			}
			if(a[2]>=a[3]>=a[1]){
				d[j]=a[2];
				z[j]=a[3];
				cho2++;
			}
			if(a[3]>=a[1]>=a[2]){
				d[j]=a[3];
				z[j]=a[1];
				cho3++;
			}
			if(a[3]>=a[2]>=a[1]){
				d[j]=a[3];
				z[j]=a[2];
				cho3++;
			}
		}
		if(cho1<=num&&cho2<=num&&cho3<=num){
			for(int j=1;j<=n;j++){
				ans=ans+d[j];
			}
		}
		if(n==2){
			if(d[1]+z[2]>=d[2]+z[1]) ans=d[1]+z[2];
			else ans=d[2]+z[1];
		}
		if(n==4){
			q[1]=d[1]+d[2]+z[3]+z[4];
			q[2]=z[1]+z[2]+d[3]+d[4];
			q[3]=d[1]+d[3]+z[2]+z[4];
			q[4]=z[1]+z[3]+d[2]+d[4];
			q[5]=d[1]+d[4]+z[3]+z[2];
			q[6]=z[1]+z[4]+d[3]+d[2];
			sort(q+1,q+6+1);
			ans=q[6];
		}
		else{
			for(int i=1;i<=n;i++){
			ans=ans+d[i]-1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
