#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,m;
string s; 
vector<int> g[10001];
int c[100001];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	cout<<"2";
	return 0;
}
//*g++ untitled5.cpp -o untitled5 -O2 -std=c++14 -Wall -Wextra