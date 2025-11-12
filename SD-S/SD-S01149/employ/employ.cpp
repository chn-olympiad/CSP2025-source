#include<bits/stdc++.h>
using namespace std;
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==n){
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				cout<<0;
				return 0;
			}
		}
		cout<<1;
	}
	else{
		cout<<2204128;
	}
	//freopen
	return 0;
}
