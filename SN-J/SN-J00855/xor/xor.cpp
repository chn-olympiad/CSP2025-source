#include<bits/stdc++.h>
using namespace std;
int a[550000];
int n,k;


int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(k==0&&a[i]==0){
			ans++;
		}
		else if(k==0&&a[i]==1&&a[i+1]==1){
			ans++;
			i++;
		}
		else if(k==1&&a[i]==1){
			ans++;
		}
	}
	
	cout<<ans;
	
	return 0;
}
