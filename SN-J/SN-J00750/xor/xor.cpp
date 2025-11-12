#include <bits/stdc++.h>
using namespace std;
int n,k,a[1005],q;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.in","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0){
			q++;
		}
	}if(k==0){
		cout<<q*(q-1)/2;
	}
	return 0;
}
