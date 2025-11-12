#include <bits/stdc++.h>
using namespace std;
long long m,n,i,j,a[100010],t,w,bao,mid,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++) cin>>a[i];
	sort(a+2,a+1+n*m);
	if(n==1&&m==1){
		cout<<"1 1";
		return 0;
	}
	t=1;w=n*m;bao=1;
	while(t<=w){
		mid=(t+w)/2;
		if(a[mid]>a[1]) bao=mid,w=mid-1;
		else t=mid+1;
	}
	k=n*m-bao+1;
	for(i=1;i<=m;i++){
		if(i%2==1)
			for(j=1;j<=n;j++){
				if(k==0) {
					cout<<i<<" "<<j;
					return 0;
				}
				k--;
			}
		else
			for(j=n;j>=1;j--){
				if(k==0){
					cout<<i<<" "<<j;
					return 0;
				}
				k--;
			}
	}
	return 0;
}
