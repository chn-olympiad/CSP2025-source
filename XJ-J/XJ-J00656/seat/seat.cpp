#include <bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int ans;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	ans=a[1];
	sort(a+1,a+n*m+1);
	int j=1,k=1;
	for(int i=n*m;i>=1;i--){
		if(a[i]==ans){
			cout << j<< " " << k;
			return 0;
		}
		if(j%2==1){
			k++;
		}
		if(j%2==0){
			k--;
		}
		if(k>n){
			k--;
			j++;
		}
		if(k<1){
			k++;
			j++;
		}
	}
	return 0;
}
