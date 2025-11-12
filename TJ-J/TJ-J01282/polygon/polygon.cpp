#include<bits/stdc++.h>
using namespace std;
const int md=998244353;
int n,a[5005],d[25];
long long ans;
void f(){
	int mx=0,s=0;
	for(int i=1;i<=n;i++){
		if (d[i]==1){
			mx=max(mx,a[i]);
			s+=a[i];
		}
	}
	if (s>mx*2) ans=(ans+1)%md;
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if (n<=20){
		for(int i=1;i<=pow(2,n)-1;i++){
			int ii=i;
			for(int j=1;j<=n;j++){
				d[j]=ii%2;
				ii/=2;
			}
			f();
		}
		cout<<ans;
	}else if (a[n]==1){
		long long c=1,p=n+n*(n-1)/2;
		for(int i=1;i<=n;i++){
			c=c*2%md;
		}
		ans=(c+md-p)%md;
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
