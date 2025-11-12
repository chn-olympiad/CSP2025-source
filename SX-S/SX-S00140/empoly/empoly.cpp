#include<bits/stdc++.h>
using namespace std;
string s;
int n,m;
int c[505];
bool d=1;
int main(){
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		c[x]++;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			d=0;
		}
	}
	if(d){
		
	}
	return 0;
}
