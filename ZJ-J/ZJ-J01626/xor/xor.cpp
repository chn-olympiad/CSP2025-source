#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005],sum=0,m,t=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	m=a[1];
	for(int i=1;i<=n;i++){
		if(m!=k&&t){
			m=m^a[i];
		}
		t=1;
		if(m==k){
			sum++;
			m=a[i+1];
			t=0;
		}
	}
	cout<<sum;
	return 0;
}
