#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[100005],maxn=-1,sum=0,ans=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		sum+=a[i];
	}
	if (n<3){
		cout<<0;
		return 0;
	}
	if (sum>2*maxn){
		ans++;
	}
	cout<<ans;
	return 0;
} 
