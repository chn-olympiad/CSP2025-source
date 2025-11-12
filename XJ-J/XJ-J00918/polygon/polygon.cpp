#include<bits/stdc++.h>
using namespace std;
long long  int  s=0,a,k[100000005],sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>k[i];
	}
	for(int i=3;i<=a;i++){
		int l=1;
		while(r<=a){
			for(int j=l;j<=;j++){
				s+=k[i];
			}
			if(2*s>k[r]) {
				sum++;
				l++;
				r++;
			}
		}
	}
	cout<<0;
	return 0;
}
