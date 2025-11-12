#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long e=0;
	unsigned long long g=0;
	for(int i=1;i<=n;i++){
		e=0;
		for(int j=i;j<=n;j++){
			e+=a[j];
		}
		if(e>2*a[n]&&n-i+1>=3){
			g++;
		}
		for(int j=i+1;j<=n;j++){
			e-=a[j];
			if(j==n){
				if(e>2*a[n-1]&&n-i>=3){
					g++;
				}
			}else if(e>2*a[n]&&n-i>=3){
				g++;
			}
			e+=a[j];
		}
	}
	cout<<g%998244353;
	return 0;
}
