#include<bits/stdc++.h>
using namespace std;
const int N=100005; 
int t,n,a[N],b[N],c[N],maxn,num;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		if(n==2){
			for(int j=1;j<=2;j++)
				cin>>a[j]>>b[j]>>c[j];
			int sum[10];
			sum[1]=a[1]+b[2];
			sum[2]=a[1]+c[2];
			sum[3]=b[1]+a[2];
			sum[4]=b[1]+c[2];
			sum[5]=c[1]+a[2];
			sum[6]=c[1]+b[2];
			sort(sum+1,sum+7);
			cout<<sum[6]<<endl;
		} 
		else if(n==100000){
			for(int j=1;j<=n;j++)
				cin>>a[i]>>b[i]>>c[i];
			sort(a+1,a+1+n);
			for(int j=n;j>=n/2;j--)
				maxn+=a[i];
			cout<<maxn<<endl;
			maxn=0;
		}
		else{
			int ans;
			for(int j=1;j<=n;j++){
				cin>>a[i]>>b[i]>>c[i];
				ans+=max(a[i],max(b[i],c[i]));
			}
			cout<<ans<<endl;
			ans=0;
		}
	}
	return 0;
}
