#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[105];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int c=1,r=1,d=1,j=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	d=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(d==a[i]){
			j=i;
		}
	}
	for(int i=m;i>=1;i--){
		if(i%2==0){
			for(int k=1;k<=n;k++){
				
			}
		}
		else{
			for(int k=n;k>=1;k--){
				
			}
		}
	}
	return 0;
}
