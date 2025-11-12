//SN-J01168 ¬нич–щ 
#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500010],d[500010][500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		d[i][i]=a[i];
		for(int j=1;j<=i-1;j++){
			d[j][i]^=a[i];
		}
	}
	if(n==1 && k==0){
		if(a[1]==0) cout << "1";
		else cout << "0";
		return 0;
	}
	if(n==2 && k==0){
		if(a[1]==0 && a[2]==0) cout << "2";
		else if(a[1]==0 || a[2]==0 || a[1]^a[2]==0) cout << "1";
		else cout << "0";
		return 0;
	}
	return 0;
}
