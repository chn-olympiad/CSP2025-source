#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int s = 0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++) cin>>a[i];
	for(int i = 1;i<=n-2;i++){
		for(int j = i+1;i<=n-1;j++){
			for(int m = j+1;m<=n;m++){
				int maxi = -1;
				int y[5];
				y[1] = a[i];
				y[2] = a[j];
				y[3] = a[m];
				for(int x = 1;x<=3;x++){
					if(y[x] > maxi) maxi = y[x];
				}
				if(a[i]+a[j]+a[m] > 2*maxi) s++;
			}
		}
	}
	cout<<s % 998244353;
	return 0;
}
