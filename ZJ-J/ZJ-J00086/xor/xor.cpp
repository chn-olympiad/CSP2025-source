#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	int maxx=0,b=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (n<=2&&k==0){
		cout<<n;
		return 0;
	}
	else {
		for (int i=1;i<=n;i++){
		if (a[i]>maxx){
			maxx=a[i];
			}
			else if (a[i]>b){
				b=a[i];
			}
		}
	}
	cout<<maxx-b;
	return 0;
}
