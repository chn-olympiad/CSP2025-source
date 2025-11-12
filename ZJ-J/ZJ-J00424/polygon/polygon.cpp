#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			for(int z=j+1;z<=n;z++){
				if(i+j>z){
					ans++;
				}
			} 
		}
	}
	cout<<ans;
	
}
