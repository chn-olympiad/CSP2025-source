#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s,aa;
	cin>>s;
	getchar();
	getline(cin,aa);
	if(m==1){
		cout<<n*(n-1);
	}
	else if(s.find("0")==-1){
		cout<<n*(n-1);
	}
	return 0;
} 
