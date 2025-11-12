#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	string s;
	for(int i=0,l;i<n;i++){
		cin>>l;
		s+=l;
	}
	cout<<s;
	return 0;
}
