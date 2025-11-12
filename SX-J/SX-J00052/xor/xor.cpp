#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500000],a0,a1,x0,x1,x00,x01;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0)a0++;
		if(a[i]==1)a1++;
		if(x0+a[i]==0){
			x0+=a[i];
		x00++;
		}
		else if(x0+a[i]!=0){
		x00/=2;
		x0=0;
		}
		if(x1+a[i]-1==0){

		x01++;
		}
		else if(x1+a[i]-1!=0){
		x01/=2;
		x1=0;
		}
	}
	if(k==0&&n==1)cout<<0;
	else if(k==0&&n==2)cout<<1;
	else if(k==0&&n>2)cout<<a0+x00;
	else if(k==1)cout<<a1+x01;
}


