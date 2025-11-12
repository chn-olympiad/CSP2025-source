#include<bits/stdc++.h>
using namespace std;
int n,a[5010],c[5010],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+a[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;i++){
			if(c[j]-c[i]>a[j]*2) ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
