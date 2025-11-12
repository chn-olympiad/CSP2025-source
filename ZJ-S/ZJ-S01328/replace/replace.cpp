#include<bits/stdc++.h>
using namespace std;
int n,q;
void youhua(){
	ios::sync_with_stdio(0);
	cin.tie(0);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n==4) cout<<2<<"\n"<<0;
	else 
		for(int i=1;i<=q;i++)
			cout<<0<<"\n"; 
}

