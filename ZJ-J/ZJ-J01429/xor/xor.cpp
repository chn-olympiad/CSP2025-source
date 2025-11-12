#include<bits/stdc++.h>
using namespace std;
int a[500001],b[500001];
bool c[500001],d[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0;
	cin>>n>>k;
	if(k==0){
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		if(b[i]==k){
			sum++;
			c[i]=1;
			d[i]=1;
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			b[j]=b[j]|a[j+i-1];
			d[j]=d[j]||c[j+i-1];
			if(!d[j]&&b[j]==k){
				sum++;
				for(int p=j;p<=j+i-1;p++){
					d[p]=1;
					c[p]=1;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}

