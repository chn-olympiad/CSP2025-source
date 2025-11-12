//许明宇-SN-J00976-西安市高新第一学校
#include <bits/stdc++.h>
using namespace std;
int n,k,a[10005],num[10005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num[a[i]]++;
	}
	cout<<num[k];
	return 0;
}
