#include<bits/stdc++.h>
using namespace std;
#define l long long
int a[100000];
l suan(l x,l y){
	l sum=0;
	for(l i=x;i<=y;i++){
		sum+=a[i];
	}
	return sum;
}
int main(){
	int n,k,cnt=0,ce1,ce2,sum=0;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(l i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(l i=1;i<=n-1;i++){
		for(l j=i+1;j<=n;j++){
			if(suan(i,j)>a[j]*2&&j-i>=3){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
