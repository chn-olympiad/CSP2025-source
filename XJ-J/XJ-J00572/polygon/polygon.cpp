#include<bits/stdc++.h>
using namespace std;
int a[5010],n,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]+a[k]>max(a[i],max(a[j],a[k]))*2){
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
