#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[10000000],n,top;
int aaa(int i,int j){
	int v;
	for(int k=i;k<=j;k++){
		v+=a[k];
	}
	return v;
}
int da(int i,int j){
	int w=0;
	for(int k=i;k<=j;k++){
		w=max(w,a[k]);
	}
	return w;
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(abs(j-i)<3){
				continue;
			}
			if(aaa(i,j)>da(i,j)*2){
				top++;
			}
		}
	}
	cout<<top%998244353;
	return 0;
}
