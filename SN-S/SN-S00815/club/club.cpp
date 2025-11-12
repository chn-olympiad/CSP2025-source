#include<bits/stdc++.h>
using namespace std;
int t,n;
struct club{
	int cluba,clubb,clubc;
}a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=1;j<=t;j++){
		cin>>n;
		int ans=0,asum=0,bsum=0,csum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].cluba>>a[i].clubb>>a[i].clubc;
			if(a[i].cluba>a[i].clubb&&a[i].cluba>a[i].clubc&&asum<n/2){
				asum++;
				ans+=a[i].cluba;
			}else if(a[i].clubb>a[i].cluba&&a[i].clubb>a[i].clubc&&bsum<n/2){
				bsum++;
				ans+=a[i].clubb;
			}else if(a[i].clubc>a[i].clubb&&a[i].clubc>a[i].cluba&&csum<n/2){
				csum++;
				ans+=a[i].clubc;
			}
			if(asum>n/2){
				if(a[i].clubb>a[i].clubc){
					bsum++;
					ans+=a[i].clubb;
				}else{
					csum++;
					ans+=a[i].clubc;
				}
			}else if(bsum>n/2){
				if(a[i].cluba>a[i].clubc){
					asum++;
					ans+=a[i].cluba;
				}else{
					csum++;
					ans+=a[i].clubc;
				}
			}else if(csum>n/2){
				if(a[i].cluba>a[i].clubb){
					asum++;
					ans+=a[i].cluba;
				}else{
					bsum++;
					ans+=a[i].clubb;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
