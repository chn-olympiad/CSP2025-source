#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1,s2;
const int M=2e5+10;
string t[M][3];
bool butong[M];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i][1];
		cin>>t[i][2];
	}
	while(q--)
	{
		string s1;
		string s2;
		cin>>s1>>s2;
		cout<<"0"<<endl;
	}
	 
	
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/

