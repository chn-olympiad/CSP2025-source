#include<bits/stdc++.h>
using namespace std;

int n;
int a[5005];
long long ans=0;

int main(){
	freopen("polygon.in","r",in);
	freopen("polygon.out","r",out);
	cin>>n;
	for(int i=1;i <= n;i++){
		cin>>a[i];
	}
	for(int i=1;i <= n;i++){
		int x=a[i],sum=a[i];
		for(int j=i+1;j <= n;j++){
			x=max(x,a[j]);
			sum+=a[j];
			if(j-i>=2 && sum>2*x)  ans++;
		}
	}
	cout<<ans;
	return 0;
}