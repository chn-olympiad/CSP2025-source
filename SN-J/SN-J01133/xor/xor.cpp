#include <bits/stdc++.h>

using namespace std;
int n,k,a[1000000],l;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n>>k;
	for(int i=0;i<n;i++) cin >> a[i];
	if(k==1){
		for(int i=0;i<n;i++){
			if(a[i]==1) l++;
		}
		cout << l;
	}
	else{
		for(int i=0;i<n;i++){
			if(a[i]==1) l++;
		}
		cout << int(l/2);
	}
}
