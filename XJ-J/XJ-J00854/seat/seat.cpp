#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n,m,j,cnm;
int ar;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cnm=n*m;
	int a[cnm+1];
	for(int i=1;i<=cnm;i++)cin>>a[i];
	ar=a[1];
	sort(a+1,a+cnm+1,cmp);
	for(j=1;a[j]>ar;j++){}
	if(j%n==0){
		if((j/n)%2!=0){
			cout<<j/n<<" "<<n;
		}else {
			cout<<j/n<<" "<<1;
		}
	}else {
		if(((j/n)+1)%2!=0){
			cout<<j/n+1<<" "<<j%n; 
		}else {
			cout<<j/n+1<<" "<<n-j%n+1;
		}
	}
	return 0;
}//xsllk1021 :ciallo~
