#include <bits/stdc++.h>
using namespace std;
long long q=1;
int n,sum;
int a[5555];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}

	if(n<=3){
		int maxn=max(a[1],a[2]);
		if(a[1]+a[2]+a[3]>2*max(maxn,a[3])){
			cout<<1<<endl;
			return 0;
		}
		else{
			cout<<0;
		}
	}
	else {
		int qqq=0;
		for(int i=4;i<=n;i++){
			q=1;
			for(long long j=i+1;j<=n;j++){
				q*=j;
			}
			for(long long j=2;j<=n-i;j++){
				q/=j;
			}
			qqq+=q;
		}
		cout<<qqq%998244353<<endl;
	}
	
	return 0;
}
