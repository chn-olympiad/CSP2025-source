#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500001],s[500001],sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) sum++;
	}
	s[0]=a[0];
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			s[j]=s[j-1]^a[j];
		}
		if(s[i]==k) sum++;
	}
	cout<<sum;
	return 0;
}
