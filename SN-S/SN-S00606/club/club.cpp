#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t;
int a[100005][5],a1,a2,a3;
signed main(){
	freopen("club3.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<100005;i++){
			for(int j=0;j<=4;j++){
				a[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		int k=n/2;
		a1=0;a2=0;a3=0;
		int m=1;
		if(a[n][1]>a[n][2]&&a[n][1]>a[n][3])a1++,m=1;
		else if(a[n][2]>a[n][1]&&a[n][2]>a[n][3])a2++,m=2;
		else a3++,m=3;
		for(int i=n-1;i>=1;i--){
			for(int j=1;j<=3;j++){
				if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]&&a1<k){
					a1++;
					a[i][1]+=a[i+1][m];
					m=1;
					break;
				}
				else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]&&a2<k){
					a2++;
					a[i][2]+=a[i+1][m];
					m=2;
					break;
				}
				else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]&&a3<k)
				{
					a[i][3]+=a[i+1][m];
					m=3;
					break;
				}
				else if((a[i][1]>=a[i][2]&&a[i][1]<=a[i][3])||(a[i][1]<=a[i][2]&&a[i][1]>=a[i][3])&&a1<k){
					a1++;
					a[i][1]+=a[i+1][m];
					m=1;
					break;
				}
				else if((a[i][2]>=a[i][1]&&a[i][2]<=a[i][3])||(a[i][2]<=a[i][1]&&a[i][2]>=a[i][3])&&a2<k){
					a2++;
					a[i][2]+=a[i+1][m];
					m=2;
					break;
				}
				else if((a[i][3]>=a[i][1]&&a[i][3]<=a[i][2])||(a[i][3]<=a[i][1]&&a[i][3]>=a[i][2])&&a3<k){
					a[i][3]+=a[i+1][m];
					m=3;
					break;
				}
				else if(a[i][1]<a[i][2]&&a[i][1]<a[i][3]&&a1<k){
					a1++;
					a[i][1]+=a[i+1][m];
					m=1;
					break;
				}
				else if(a[i][2]<a[i][1]&&a[i][2]<a[i][3]&&a1<k){
					a2++;
					a[i][2]+=a[i+1][m];
					m=2;
					break;
				}
				else{
					a[i][3]+=a[i+1][m];
					m=3;
					break;
				}
			}
		}
		cout<<max(a[1][1],max(a[1][2],a[1][3]))<<endl;
	}
	return 0;
}
