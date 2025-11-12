#include <iostream>
using namespace std;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin >> n >> k;
	for(int i=0;i<n;i++)cin >> a[i];
	for(int i=0;i<n;i++){
		if(a[i]==k)ans++;
	}
	cout << ans;
	return 0;
}
