#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,a[N],cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		int maxx=0,ans=0;
		for(int j=1;j<=i;j++){
			ans+=a[j];
			if(a[j]>maxx){
				maxx=a[j];
			}
			
	}
		for(int x=1;x<=i;x++){
			
			if(ans>maxx*2){
				cnt++;
			}
			
		}
	}
	cout<<cnt%998244353;
	return 0;
}
