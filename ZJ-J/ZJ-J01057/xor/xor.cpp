#include<bits/stdc++.h>
using namespace std;
long long k,n,a[500010],x=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1&&k==0)x++;
		else if(k==0){
			ans+=x/2;
			x=0;
		}
		if(k==1&&a[i]==1)
			ans++;
		if(k==0&&a[i]==0){
			ans++;
		}
	}
	if(k==0&&ans==0){
		cout<<n/2;
		return 0;
	}
	cout<<ans;
	return 0;
}

