#include<bits/stdc++.h>
using namespace std;
int sum;
int c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[m*n+10];
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
		if(a[1]<a[i]){
			sum++;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=n;j>0;j--){
			c=(sum/n)+1;
			if(c%2==1){
				r=sum%m+1;
			}else{
				r=m-(sum%m);
			}
		}
	}
	cout<<c<<" "<<r;


	fclose(stdin);
	fclose(stdout);
return 0;
}
