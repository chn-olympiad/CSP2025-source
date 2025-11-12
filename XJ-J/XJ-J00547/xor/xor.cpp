#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,k,a[N],s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			s++;
			a[i]=-1;
		}
	}
	cout<<s;
	return 0;
}
