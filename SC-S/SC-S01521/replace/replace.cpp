#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,q,x=0;
	cin>>n>>q;
	string a,b;
	cin>>a>>b; 
	for(int i=0;i<min(a.size(),b.size());i++){
		if(a[i]!=b[i]) x++;
	}
	if(q==1){
		cout<<x/2;
		return 0;
	}
	cout<<n/2;
	return 0;
} 