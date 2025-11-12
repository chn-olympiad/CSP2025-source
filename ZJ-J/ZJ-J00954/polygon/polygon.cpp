#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]+a[k]>a[k]*2){
					ans++;
				}
			}
		}
	}
	if(n>=4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int z=k+1;z<=n;z++){
						if(a[i]+a[j]+a[k]+a[z]>a[z]*2){
							ans++;
						}
					}
				}
			}
		}
	}
	cout<<ans%988244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
