#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int n,m=0,c=0;
	cin>>n;
	int a[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i];
		
	}
	for(int i=3;i<=n;i++){
		for(int j=0;j<=i-2;j++){
			for(int k=j+1;k<=i-1;k++){
				for(int l=k+1;l<=i;l++){
					if(a[j]+a[k]+a[l]>a[j] and a[j]+a[k]+a[l]>a[k] and a[j]+a[k]+a[l]>a[l] and a[j]!=0 and a[k]!=0 and a[l]!=0){
						c++;
						cout<<a[j]<<' '<<a[k]<<' '<<a[l]<<' '<<a[j]+a[k]+a[l]<<endl;
					}
				}
			}
		}
	}
	cout<<c;
	return 0;
}
