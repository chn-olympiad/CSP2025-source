#include<bits/stdc++.h>
using namespace std;
long long a[5500];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=3){
		if(2*a[n]<a[1]+a[2]+a[3]){
			cout<<1;
		}
		else cout<<0;
	}
	/*for(int n;i>=3;i--){
		int t=a[i]*2;
		for(int j=i;j>=2;j--){
			int k=j;
			int f=a[k]+a[i];
			while(1){
				k--;
				f+=a[k];
				if(f>t){
					ans+=k
				}
			}
		}
	}*/
	return 0;
}
