#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,a[101],ai,num=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(i>0&&a[i]>a[0])  num++;
	}
	c=num/n+1;
	if(c%2==0){
		r=c*n-num;
	}
	else{
		r=num-(c-1)*n+1;
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
