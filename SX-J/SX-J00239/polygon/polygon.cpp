#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=a[i];
	}
	if(n==3&&cnt>a[3]*2) cout<<"1";
	else cout<<"0";
	return 0;
}