#include<bits/stdc++.h>
using namespace std;
int a[5000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int js=3;
	int b=0;
	int z=0;
	int ko=0;
	for(int i=1;i<=n;i++){
		for(int k=i;k<=n-js+1-ko;k++){
			b=a[k];
			for(int j=k+1+ko;j<=k+js-2+ko;j++){
				b+=a[j+2];
			}
			if(b+a[k+js-1+ko]>a[k+js-1+ko]*2){
				z++;
			}
		}
		ko++;
	}
	cout<<z;
	return 0;
}
