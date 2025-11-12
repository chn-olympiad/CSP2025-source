#include<bits/stdc++.h> 
using namespace std;
int b,n,i,j;
int c1=0,c2=0,c3=0;
int v;
int ans=0;
long long a[1000][1000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>b;
	for(int k=0;k<b;k++){
		cin>>n;
		for(int l=0;l<n;l++){
			int max=-1;
			for(int u=1;u<=3;u++){
				cin>>j;
				a[l][u]=j;
				if(j>max){
					int max=j;
					int v=u;
				}
			}
			if(c1<=n/2&&v==1){
				ans+=max;
				c1++;
			}else if(c1>n/2&&v==1&&a[l][2]>=a[l][3]){
				ans+=a[l][2];
				a[l][2]=-1;
				c2++;
			}else if(c1>n/2&&v==1&&a[l][2]<=a[l][3]){
				ans+=a[l][3];
				a[l][3]=-1;
				c3++;
			}
			if(c2<=n/2&&v==2){
				ans+=max;
				c2++;
			}else if(c2>n/2&&v==2&&a[l][1]>=a[l][3]){
				ans+=a[l][1];
				a[l][1]=-1;
				c1++;
			}else if(c2>n/2&&v==2&&a[l][1]<=a[l][3]){
				ans+=a[l][3];
				a[l][3]=-1;
				c3++;
			}
			if(c3<=n/2&&v==3){
				ans+=max;
				c3++;
			}else if(c3>n/2&&v==3&&a[l][2]>=a[l][1]){
				ans+=a[l][2];
				a[l][2]=-1;
				c2++;
			}else if(c3>n/2&&v==3&&a[l][2]<=a[l][1]){
				ans+=a[l][1];
				a[l][1]=-1;
				c1++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
