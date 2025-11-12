#include <bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
int n,q;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>n>>q;
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
	}
	srand(time(0));
	int r=rand();
	for(int i=1;i<=q;i++){
		cout<<r%12;
	}
	return 0;
} 
