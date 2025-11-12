#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				int max1,x;
				x=a[i]+a[j]+a[k];
				max1=max(a[i],max(a[k],a[j]));
				if(x>2*max1){
					ans++;
				}
			}
		}
	}
	cout<<ans;
}
