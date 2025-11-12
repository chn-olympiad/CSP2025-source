#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],cou=0;
int zh(int n){
	int j=0;
	int q=0;
	while(n!=0){
		q=q+(n%2)*pow(10,j);
		n/=2;
	}
	return q;
}
int xoor(int aa,int bb){
	int a1,b1,c1=0;
	int j=0;
	while(aa!=0&&bb!=0){
		a1=aa%10;
		b1=bb%10;
		if(a1==b1){
			c1+=0*pow(10,j);
			j++;
			aa/=10;
			bb/=10;
		}
		else{
			c1+=1*pow(10,j);
			j++;
			aa/=10;
			bb/=10;
		}
	}
	return c1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	k=zh(k);
	for(int i=1;i<n;i++){
		int coo=0;
		a[i]=zh(a[i]);
		for(int j=i+1;j<=n;j++){
			a[j]=zh(a[j]);
			coo+=xoor(a[j],a[j-1]);
		}
		if(coo==k) cou++;
	}
	cout<<cou;
	return 0;
}
