#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n;
	cin>>t>>n;
	int a1[1000000],a2[1000000],a3[1000000];
	for(int i=0;i<n;i++){
		cin>>a1[i]>>a2[i]>>a3[i];
	}
	sort(a1,a1+n,cmp);
	sort(a2,a2+n,cmp);
	sort(a3,a3+n,cmp);
	int d,s,b;
	for(int i=0;i<=n/2;i++){
		d=a1[i]
		s=a2[i]
		b=a3[i]
	}
	cout<<d+s+b;
	return 0;
}
