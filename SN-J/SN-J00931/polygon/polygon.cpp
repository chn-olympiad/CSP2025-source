#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a,b=0;
	cin>>a;
	for(int i=1;i<=a;i++){
		b+=a/i+2;
	} 
	cout<<b; 
	return 0;
}
