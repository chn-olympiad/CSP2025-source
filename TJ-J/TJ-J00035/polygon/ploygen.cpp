#include<bits/stdc++.h>
using namespace std;
int sum=0;
int main(){
	freopen("polygen.in","r",stdin);
	freopen("ploygen.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	cout<<n;
	return 0;
}
