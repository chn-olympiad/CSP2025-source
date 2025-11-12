#include<bits/stdc++.h>
using namespace std;
int main(){
	int s;
	cin>>s;
	int a[10000];
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	sort(a+1,a+s+1);
	if(a[1]+a[2]+a[3]>2*a[3])cout<<1;
	else cout<<0;
	return 0;
}
