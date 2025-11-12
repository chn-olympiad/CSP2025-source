#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005],c[1000005];
int a1[5],a2[5],a3[5];
int t,n;
bool f1=1,f2=1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		long long sum=0;
		f1=1,f2=1;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0) f1=0;
			if(c[i]!=0) f2=0;
		}
		if(f1==1){
			sort(a+1,a+n+1);
			for(int i=n;i>n/2;i--){
				sum+=a[i];
			}
			cout<<sum<<endl;
			continue;
		}
		if(n==2){
			int mmax=0;
			mmax=max(b[1]+a[2],max(a[1]+b[2],max(a[1]+c[2],max(b[1]+c[2],max(c[1]+a[2],c[1]+b[2])))));
			cout<<mmax<<endl;
		}
	}
	return 0;
}