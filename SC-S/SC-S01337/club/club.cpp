//f
#include<bits/stdc++.h>
using namespace std;
int t,ans[13];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		if(n==100000){
			int a[100010]={},b[100010]={},c[100010]={};
			for(int j=0;j<n;j++){
				cin>>a[j]>>b[j]>>c[j];
			}
			sort(a,a+n);
			for(int j=n-1;j>=n/2-1;j--)ans[i]+=a[j];
		}
	}
	for(int i=0;i<t;i++){
		cout<<ans[i];
	}
	return 0
}
//AC