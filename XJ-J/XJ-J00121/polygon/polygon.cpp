#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,num=988244353;
	ll ans=0;
	cin>>n;
	int a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		
	}cout<<ans%num;
	fclose(stdin);
	fclose(stdout);

	return 0;
}
