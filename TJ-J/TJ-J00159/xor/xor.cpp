#include<bits/stdc++.h>//xor
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout); 
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int h,ans=0,l,r;
	bool fla=1;
	for(int i=1;i<=n;i++){
		if(fla==1){
			h=a[i];
			fla=0;
			if(h==k){
				ans++;
			}
			continue;
		}
		if(h==k){
			ans++;
			fla=1;
		}
		else {
			h=h^a[i];
		}
	}
	cout<<ans;
	return 0;
}
