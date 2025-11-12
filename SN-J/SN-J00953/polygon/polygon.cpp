//Ñ¦ŞÈÆ½ ¸¨ÂÖÖĞÑ§ SN-J00953
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[5010];
	int sum=0;
	for (int i=1; i<=n; i++){
		cin>>a[i];
	}
	int fac=1,fac1=1;
	for (int i=3; i<=n; i++){
		for (int j=1; j<=n; j++){
			for (int k=1; k<=n; k++){
				fac*=k;
				for (int l=1; l<=i; l++){
					fac1*=l;
				}
				fac/=fac1;
			}
		}
	}
	cout<<fac%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
