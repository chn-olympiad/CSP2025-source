#include<iostream>
using namespace std;
int n,k,a[500005],b[500005],sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=int(a[i]^b[i-1]);
		if(a[i]==k){
			sum++;
			b[i]=-1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(int(b[j]^b[i-1])==k){
				sum++;
				b[i]=int(a[i]^b[i-1]);
				i=j+1;
				for(int k=j+1;k<=n;k++)b[i]=int(a[i]^b[i-1]);
			}
		}
	}
	cout<<sum;
	return 0;
}
