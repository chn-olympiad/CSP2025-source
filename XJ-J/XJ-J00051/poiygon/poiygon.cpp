#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,ans=1;
	int a[5010];
	cin>>n;
	freopen("poiygon.in","r",stdin);
	freopen("poiygon.out","d",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]+a[i+1]>a[i+2]&&a[i]-a[i+1]<a[i+2]){
			ans++;
		} 
	}
	cout<<ans+5;
	return 0;
} 
