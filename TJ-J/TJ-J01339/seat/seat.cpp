#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define cin in
#define cout out
#define endl '\n'
int main(){
	fstream in,out;
	in.open("seat.in",ios::in);
	out.open("seat.out",ios::out);
	ll n,m;
	cin >> n >> m;
	ll s[105]={};
	for(int i=0;i<n*m;i++){
		cin >> s[i];
	}
	ll a=s[0];
	sort(s,s+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(s[i]==a){
			a=n*m-i-1;
		}
	}
	ll b=1,c=1;
	int u=1;
	for(int i=0;i<a;i++){
		c+=u;
		if(c>n){
			c=n;
			u=-1;
			b++;
		}else if(c==0){
			c=1;
			u=1;
			b++;
		}
	}
	cout << b <<' '<< c << endl;
	return 0;
}