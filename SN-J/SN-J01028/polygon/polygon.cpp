#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005],b[5005],sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	b[0]=a[0];
	for(int i=1;i<n;i++){
		b[i]=b[i-1]+a[i];
		if(b[i]>a[i]*2){
			sum++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(b[i]-b[j]+b[j-1]>a[i]*2){
				sum++;
			}
		}
	}cout<<sum+2
	return 0;
}
