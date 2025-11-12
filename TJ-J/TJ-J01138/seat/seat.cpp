#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,c=1,r=1;
	cin>>n>>m;
	
	int a[n*m]={0};
	for(int i=1;i<=n*m;i++)
	cin>>a[i];
	int f=a[1];
	sort(a+1,a+n*m+1);
	
	for(int i=m*n;i>0;i--){
	if(i!=m*n){
	if(c%2==1)
	r++;
	else
	r--;
}
	if(r>n){
		r=n;
		c++;
	}
	if(r<1){
		r=1;
		c++;
	}
		if(a[i]==f){
			cout<<c<<' '<<r;
		}	
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
