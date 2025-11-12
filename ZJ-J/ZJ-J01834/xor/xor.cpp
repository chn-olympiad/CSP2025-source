#include<bits/stdc++.h>
using namespace std;
const int mx=5e5+10;
int a[mx];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	long long ans=0;
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans++;
			else if(a[i]^a[i+1]==0){
				ans++;
				i++;
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			if(a[i]==k)ans++;
		}
	}
	cout<<ans;
	return 0;
}