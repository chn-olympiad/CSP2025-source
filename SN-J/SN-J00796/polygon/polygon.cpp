#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for (int x=1;x<=n-2;x++){
		for (int y=x+1;y<=n-1;y++){
			for(int z=y+1;z<=n;z++){
				int m=max(a[x],max(a[y],a[z]));
				if ((a[x]+a[y]+a[z])>2*m){
					ans++;
				}
			}
		}
	}
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
