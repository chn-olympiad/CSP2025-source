#include <iostream>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	long long nans=0;
	for(int i=m;i<=n;i++){
		long long ans=n;
		for(int j=n-1;j>n-i;j--)ans=ans*j%998244353;
		nans=(nans+ans)%998244353;
	}
	cout << nans%998244353;
}
