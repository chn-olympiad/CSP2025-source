#include<bits/stdc++.h>
using namespace std;
int n,A[5010],ans;
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.ont","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>A[i];
	}
	for(int i=1;i<=n-2;i++){
		int g=0;
		for(int j=1;j<=i;j++){
			g+=j;
		}
		ans+=g;
	}
	cout<<ans%998244353;
}
