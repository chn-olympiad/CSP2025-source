#include<bits/stdc++.h>
using namespace std;
int n;
long long a[5001];
bool f(int s,int w){
	long long max=0,h=0;
	for(int i=s;i<=w;i++){
		h=h+a[i];
		if(a[i]>max){
			max=a[i];
		}
	}
	if(h-max>max){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long z=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		for(int j=0;j<=n-i-1;j++){
			if(f(j,j+n-1)){
				z++;
			}
		}
	}
	cout<<z%998244353;
	return 0;
}
