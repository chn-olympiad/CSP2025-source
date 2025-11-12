#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int k,cnt=0;
	cin>>k;
	int a[k+5];
	for(int i=1;i<=k;i++){
		cin>>a[i];
		cnt+=a[i];
	}
	cout<<cnt;
	return 0;
}
