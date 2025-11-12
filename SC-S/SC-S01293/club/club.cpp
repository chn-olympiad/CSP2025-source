#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int t,n,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int a[1000050];
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>a[i+1]>>a[i+1];
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}