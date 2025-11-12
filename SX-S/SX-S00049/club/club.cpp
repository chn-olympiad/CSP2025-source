#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int a[N],b[N],c[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
 	int n,sum=0;
 	int sum1=0,sum2=0,sum3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=1;i<=n;i++){
			if(sum1<=n/2&&sum2<=n/2&&sum3<=n/2){
				if(a[i]>b[i]&&a[i]>c[i]){
					sum+=a[i];
					sum1++;
				}
				if(b[i]>c[i]&&b[i]>a[i]){
					sum+=b[i];
					sum2++;
				}
				if(c[i]>b[i]&&c[i]>a[i]){
					sum+=c[i];
					sum3++;
				}
			}
			else if(sum1>n/2&&sum2<=n/2&&sum3<=n/2){
				if(b[i]>c[i]){
					sum+=b[i];
					sum2++;
				}
				if(c[i]>b[i]){
					sum+=c[i];
					sum3++;
				}
			}
			else if(sum1<=n/2&&sum2>n/2&&sum3<=n/2){
				if(a[i]>c[i]){
					sum+=a[i];
					sum1++;
				}
				if(c[i]>a[i]){
					sum+=c[i];
					sum3++;
				}
			}
			else if(sum1<=n/2&&sum2<=n/2&&sum3>n/2){
				if(b[i]>a[i]){
					sum+=b[i];
					sum2++;
				}
				if(a[i]>b[i]){
					sum+=a[i];
					sum1++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}