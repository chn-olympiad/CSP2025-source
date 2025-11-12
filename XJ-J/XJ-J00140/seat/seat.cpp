#include<bits/stdc++.h>
using namespace std;
bool cmp(int p,int q){
	return p>q;
}
int dx[2]={-1,1};
int dy[2]={-1,1};
int main(){
	freonpe("seat.in","r",stdin);
	freonpe("seat.out","w",stdout);
	int n,m;
	int a[101];
	cin >> n >> m;
	for(int i=0;i<n*m;i++){
		cin >> a[i];
	}
	int c=0,r=0,ans=0;
	int sum;
	sum=a[0];
	sort(a,a+n*m+1,cmp);
	for(int i=0;i<=n*m;i++){
		if(sum==a[i]){
			ans=i;
		}
	}
	if(ans%m==0){
		c=ans/m;
	}
	else{
		c=ans/m+1;
	}
	if(ans%n==0){
		r=ans/n+1;
	}
	else{
		r=ans/n;
	}
	cout<< c << " " << r ;
	fcolve(stdin);
	fcolve(stdout);

	return 0;
} 
