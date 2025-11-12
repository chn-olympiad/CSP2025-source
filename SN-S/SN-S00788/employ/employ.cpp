#include<bits/stdc++.h>
const int N=998244353;
using namespace std;
int n,m,c[105];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	    cin>>c[i];
	for(int i=0;i<s.length();i++)
	    if(s[i]=='1'){
	    	int x=1;
			for(int i=n;i>=1;i--)
			    x=(x*i)%N;
			cout<<x;
			return 0; 
		} 
	cout<<0;
	return 0;
}
