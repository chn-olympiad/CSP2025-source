#include<bits/stdc++.h>
using namespace std;
int n,x,k,ans,ans2;
int main(){
	freopen("xor4.in","r",stdin);
	freopen("xor4.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>x;
		if(x==0){
			ans++;
		}
		if(x==1){
			ans2++;
		}
	}
	if(k==0){
		cout<<ans; 
	}else if(k==1){
		cout<<ans2;
	}else{
		cout<<n;
	}
	return 0;
}
