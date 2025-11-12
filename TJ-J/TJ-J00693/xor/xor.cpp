#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[10000000],n,top,b[100000],m;
int aaa(int i,int j){
	int v;
	for(int k=i;k<=j;k++){
		v^=a[k];
	}
	return v;
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int v=aaa(i,j);
			if(v==m){
				if(v==0){
					cout<<1;
					return 0;
				}
				cout<<m;
				return 0;
			}
			if(v>m){
				continue;
			}else{
				b[top++]=v;
			}
		}
	}
	int big=1;
	for(int i=0;i<top;i++){
		if(b[i]>m){
			continue;
		}
		big=max(big,b[i]);
	}
	cout<<big;
	return 0;
}
