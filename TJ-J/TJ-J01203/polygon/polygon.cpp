#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<3) {
		cout<<0;
		return 0;
	}
	int a,b,c;
	cin>>a>>b>>c;
	if(a+b+c>a*2&&a+b+c>b*2&&a+b+c>c*2) cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
