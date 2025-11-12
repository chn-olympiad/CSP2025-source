#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5005];
int ans;
int he ;
int maxx=-1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			he=0;
			maxx=-1;
			for(int k=1;k<=i;k++){
				he+=a[j+k];
				if(a[j+k]>maxx)maxx=a[k];
			}
			if(maxx*2<he)ans++;
			//cout<<he<<" "<<i<<" "<<j<<" "<<maxx<<" "<<endl;
		}
		ans%=mod;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
