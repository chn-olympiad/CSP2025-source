//SN-J00692
#include<bits/stdc++.h>
using namespace std;
int r,k,a[105],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>r>>k;
	for(int i=1;i<=r;i++){
		cin>>a[i];
		if(i<r){
			ans+=i;
		}
	}
	cout<<ans;
	return 0;
}
