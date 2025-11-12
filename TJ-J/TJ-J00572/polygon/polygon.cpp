#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],l,r,h,b[5005];
void f(int g){
	for(int i=1;i<=g-3;i++){
		int y=b[g-1]-b[i-1];
		for(int j=i;j<g;j++){
			if(y-a[j]+a[g]>a[g]*2){
				h++;
				h%=998244353; 
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=3;i<=n;i++){
		if(b[i]>a[i]*2){
			h++;
			h%=998244353; 
			f(i);
		}
	}
	cout<<h;
	return 0;
}
