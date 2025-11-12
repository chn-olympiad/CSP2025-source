#include<bits/stdc++.h>
using namespace std;
long long n,k,x;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(k==a[i]){
			x++;
		}
		if(k==0&&a[i]==a[i-1]&&a[i]!=0){
			x++;
			a[i]=0;
		}
	}
	cout<<x;
	return 0;
}
