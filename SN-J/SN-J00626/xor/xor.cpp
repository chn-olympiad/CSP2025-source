#include <bits/stdc++.h>
using namespace std;
int a[100010];
int n,k;
int x[100010];
bool yihuo(int l,int r){
	int he=a[l];
	for (int i=l;i<=r;i++){
		he+=he|a[i];
	}
	if (he==k){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int shu=0;
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			if (yihuo(i,j)){
				 shu++;
			}
		}
	}
	cout<<shu;
	return 0;
}
