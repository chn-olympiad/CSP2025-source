//SN-J00364 张柏洋 延安市新区培文学校
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[200000005],sum=0,i=1;
	long long d=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(i<=n){
		d^=a[i];
		if(d==k){
			sum++;
			d=0;
		}
		i++;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
