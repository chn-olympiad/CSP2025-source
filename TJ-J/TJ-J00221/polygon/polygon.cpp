#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int s[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;return 0;
	}
	else if(n==3){
		//cout<<a[3]<<endl;
		if(a[1]+a[2]+a[3]>a[3]*2)cout<<1;
		else cout<<0;
		return 0;
	}
	long long ans=0;
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	//for(int i=1;i<=n;i++)cout<<s[i]<<' ';
	//cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			if(a[j]*2<s[j]-s[i-1]){
				ans++;
				//cout<<i<<' '<<j<<endl;
			}
		}
	}
	cout<<ans;
	return 0;
}

