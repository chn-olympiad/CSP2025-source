#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100005],sum,ans;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			sum=0;
			for(int k=j;k<=j+i-1;k++){
				if(a[k]==-1){
					sum=-1;
					break;
				}
				else{
					sum^=a[k];
				}
			}
			if(sum==m){
				ans++;
				for(int k=j;k<=j+i-1;k++)a[k]=-1;
			}
		}
	}
	cout<<ans;
	return 0;
}

