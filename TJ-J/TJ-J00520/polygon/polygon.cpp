#include<bits/stdc++.h>
using namespace std;
long long int n,a[100005],cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]+a[i+1]+a[i+2]+a[i+n]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
