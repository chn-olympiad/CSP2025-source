#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105];
	cin>>n>>m;
	for (int i = 1;i<=n*m;i++){
		cin>>a[i];
	}
	int b = a[1],c;
	sort(a+1,a+n*m+1);
	for (int i = n*m;i>=1;i--){
		if (a[i]==b){
			c=n*m-i+1;
		}
	}
	int sum=1;
	for (int i = 1;i<=n;i++){
		if (i%2!=0){
			for (int j = 1;j<=m;j++){
				if (sum==c){
					cout<<i<<" "<<j;
					return 0;
				}else{
					sum++;
				}
			}
		}else{
			for (int j = m;j>=1;j--){
				if (sum==c){
					cout<<i<<" "<<j;
					return 0;
				}else{
					sum++;
				}
			}
		}
	}
	return 0;
}
