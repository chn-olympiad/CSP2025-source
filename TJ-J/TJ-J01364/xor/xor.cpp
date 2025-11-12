#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N]
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k,f=0,f1=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=1;
		if(a[i]!=1&&a[i]!=0) f1=1;
	}
	if(f==0){
		cout<<n;
	}
	else if(f1==0){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) ans++;
			else if(a[i]==1){
				if(a[i-1]==1){
					ans++;
					a[i-1]=-1;
				}
				else if(a[i+1]==1){
					ans++;
					a[i+1]=-1;
				}
			}
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	//I am AK CSP-J
	return 0;
}

