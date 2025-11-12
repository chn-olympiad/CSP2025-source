#include<bits/stdc++.h>
using namespace std;
long long t,n,a,b,c,ans=0,a1[100005],a2[100005],a3[100005],b1[205],b2[205],b3[205],maxx=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int sum=1;
		cin>>n;
		ans = 0;
		for(int j = 1;j<=n;j++){
			cin>>a>>b>>c;
			if(a>=b&&a>=c){
				a1[sum++]=a;
			}else if(b>=a&&b>=c){
				a2[sum++]=b;
			}else{
				a3[sum++]=c;
			}
		}
		sort(a1+1,a1+1+n);
		sort(a2+1,a2+1+n);
		sort(a3+1,a3+1+n);
		for(int j=n;j>=n/2+1;j--){
			ans+=a1[j]+a2[j]+a3[j];
			a1[j]=0;
			a2[j]=0;
			a3[j]=0; 
		}
		cout<<ans<<endl;
	} 
	return 0;
}
