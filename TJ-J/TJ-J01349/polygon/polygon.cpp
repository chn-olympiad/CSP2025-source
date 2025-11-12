#include<bits/stdc++.h>
using namespace std;
int n,a[5010],s[5010]={0},ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int j=1;j<=n-2;j++){
		for(int k=j+1;k<=n-1;k++){
			for(int l=k+1;l<=n;l++){
				if(a[j]+a[k]+a[l]>a[l]*2){
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
