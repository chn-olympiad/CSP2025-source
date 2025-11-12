#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001],c[100001];
int m(int a1,int b1){
	int c1=0;
	for(int i=a1;i<=b1;i++){
		c1=max(c1,a[i]);
	}
	return c1;
}
int main(){
	freopen("polygon2.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]+b[i-1];
		c[i]=max(c[i-1],a[i]);
	}
	long long num=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(j-i>=2&&b[j]-b[i-1]>2*m(i,j)){
				num++;
				num%=998244353;
			}
		}
	}
	cout<<num%998244353;
	return 0;
}
