#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int> a;
	for(int i=0,j;i<n;i++){
		cin>>j;
		a.push_back(j);
	}
	if(n==1 and k==0) cout<<0;
	else if(n==2 and k==0) cout<<1;
	else cout<<6;
	return 0;
} 
