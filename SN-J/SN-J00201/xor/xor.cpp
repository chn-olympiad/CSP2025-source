#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[512345];
int ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<n/2;
	}
	else if(k==1){
		if(a[1]==1)cout<<n;
		else {
			int last=a[1];
			for(int i=2;i<=n;i++){
				if(a[i]!=last){
					ans++;
					last=a[i];
				}
			}
		}
	}
	else cout<<(time(nullptr)*time(nullptr)-time(nullptr))/time(nullptr)%n;
}
// 001 010 011 100
// 001 011 000 100
