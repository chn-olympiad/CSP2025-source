#include<iostream>
#include<cmath>
using namespace std;
long long e(int r){
	long long s=0,c=0;
	while(r){
		s+=r%2*pow(10,c);
		c++;
		r/=2;
	}
	return s;
}
long long yh(long long x,long long y){
	long long s=0,c=0;
	x=e(x);
	y=e(y);
	while(x!=0||y!=0){
		if(x%10!=y%10)
			s+=pow(2,c);
		x/=10;
		y/=10;
		c++;
	}
	return s;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s,z=0,l;
	cin>>n>>k;
	int a[n+5],b[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int f=1,j;
		s=a[i];
		if(a[i]!=k){
			for(j=i+1;j<=n;j++){
				if(yh(s,a[j])==k){
					z++;
					i=j+1;
					break;
				}
				else s=yh(s,a[j]);
			}
		}
		else z++;
	}
	cout<<z;
	return 0;
}
