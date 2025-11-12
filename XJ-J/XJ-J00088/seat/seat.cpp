#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int lum=0,c=0,r=0;
int main(){
	freopen("seat.in","r",stdin); 
	cin>>n>>m;
	int s=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];//k为小R的成绩 
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==k){
			s=n*m-i+1;//s储存小R成绩是第几 
		}
	}
	int sum=0;//列 
	c=s/m;//行 
	r=s%m;//余 
	if(r!=0) c++;
	if(c%2==0){
		for(int i=m;i>=1;i--){
			lum=m-i+1;
		}
	}
	else{
		sum=1+c;
	}
	if(sum>m) sum-=m;
	if(sum==0) sum=m;
	freopen("seat.out","w",stdout); 
	cout<<c<<" "<<sum;
	return 0;
}

