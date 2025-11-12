#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,sum=0; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005],sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int b[5005];
	b[0]=a[0];
	for(int i=1;i<n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			for(int k=0;k<=j;k++){
				if(b[i]-b[j]+b[k]-a[i]*2>0){
					sum++;
				}
			}
		}
	}
	cout<<sum-a[0];
	return 0;
} 
