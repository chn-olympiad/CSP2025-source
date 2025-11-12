#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	int n,a[5010];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(a[0]+a[1]>a[2])cout<<1;
	return 0;
}

