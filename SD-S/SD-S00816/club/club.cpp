#include<bits/stdc++.h>
using namespace std;
int t;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int s1=1,a1=1,b1=1,c1=1;
		int ans=0;
		int n;
		cin>>n;
		int a[100005]={},b[100005]={},c[100005]={};
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(c[i]!=0){
				s1=0;
			}
		}
		if(s1){
			int d[100005]={};
			for(int j=1;j<=n;j++){
				ans=ans+a[j];
				d[j]=b[j]-a[j];
			}
			sort(d+1,d+n+1,cmp);
			for(int j=1;j<=n/2;j++){
				ans=ans+d[j];
			}
			cout<<ans<<endl;
		}else{
			for(int j=1;j<=n;j++){
				if(a[j]>=b[j]&&a[j]>=c[j]){
					if(a1<=n/2){
						ans=ans+a[j];
						a1++;
					}
				}
				if(b[j]>=a[j]&&b[j]>=c[j]){
					if(b1<=n/2){
						ans=ans+b[j];
						b1++;
					}
				}
				if(c[j]>=b[j]&&c[j]>=a[j]){
					if(c1<=n/2){
						ans=ans+c[j];
						c1++;
				    }
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

