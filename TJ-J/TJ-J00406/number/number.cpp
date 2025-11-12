#include<bits/stdc++.h>
#define int long long
using namespace std;
string a;
int c[12];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9'){
			c[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(c[i]--){
			cout<<i;
		}
	}
	return 0;
} 
