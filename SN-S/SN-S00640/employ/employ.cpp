//Ñ¦ÞÈÆ½   ¸¨ÂÖÖÐÑ§    SN-S00640 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int c[509];
	int n,m;
	cin>>n>>m;
	int s;
	cin>>s;
	for (int i=1; i<n; i++){
		cin>>c[i];
	}
	int fac=1;
	for (int i=18; i<=n; i++){
		fac=i;
	}
	cout<<fac%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
