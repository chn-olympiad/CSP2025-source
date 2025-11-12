#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int a[500005],f[500005];
long long cnt=0,k,n;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=a[1];
	for(int i=2;i<=n;i++){
		if(sum==k){
			cnt++;
			sum=a[i];
			continue;
		}
		sum=sum^a[i];
	}
	if(sum==k) cnt++;
	cout<<cnt;
	return 0;
}
