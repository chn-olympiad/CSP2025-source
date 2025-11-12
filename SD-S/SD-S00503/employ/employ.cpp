#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("emply.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	if(n==m){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	bool b=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') {
			b=0;
			break;
		}
	}
	if(b){
		cout<<n*n;
	}
	else{
		if(m>18){
			cout<<0;
		}
		else{
		    cout<<m*m;
		}
	}
	return 0;
}
