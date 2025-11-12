#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}
		return 0;
	}
	for(int i=1;i<=1000;i++){
		for(int j=i;j<=1005;j+=3){
			if(a[j]+a[j+1]>a[j+2]){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}