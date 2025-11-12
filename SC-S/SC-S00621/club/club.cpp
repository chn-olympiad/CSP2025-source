#include<bits/stdc++.h>
using namespace std;
int t,n,maxn=-1e9+7,a[100005],b[100005],c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				cin>>a[i]>>b[i]>>c[i];
			}
			sort(a+1,a+1+n);
			for(int i=n;i>=1;i--){
				maxn+=a[i]; 
			}
			cout<<maxn<<'\n';
		}
	}
	return 0;
}