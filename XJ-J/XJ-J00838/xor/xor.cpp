#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,a[50010],ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2){
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				ans++;
			}
			else if(ans==0&&(a[i]-a[i+1]==k||a[i+1]-a[i]==k)){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
