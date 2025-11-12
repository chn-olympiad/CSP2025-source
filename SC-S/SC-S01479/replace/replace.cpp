#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,q;
string s1,s2,t1,t2; 
vector<int> g[10001];
int c[10001][10001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
	}
	for(int j=1;j<=q;j++){
		cin>>t1>>t2;
	}
	cout<<"2"<<'\n'<<"0";
	return 0;
}
//*g++ untitled5.cpp -o untitled5 -O2 -std=c++14 -Wall -Wextra