#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}int ma_x=0,l=1;
	for(l;l<=n;l++){
		int sum=0;
		sum^=a[l];
		if(sum==k){
			ma_x++;
			continue;
		}
		for(int j=l+1;j<=n;j++){
			sum^=a[j];
			if(sum==k){
				l=j+1;
				ma_x++;
				break;
			}
		}
	}
	cout<<ma_x;
	return 0;
}
