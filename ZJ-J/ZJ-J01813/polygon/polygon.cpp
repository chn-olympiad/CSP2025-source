#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	if(n<3) cout<<0;
	else if(n==3) cout<<1;
	else cout<<2;
	fclose(stdin);
	fclose(stdout);
}
