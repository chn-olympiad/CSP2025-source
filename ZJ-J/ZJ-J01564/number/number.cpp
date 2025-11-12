#include <bits/stdc++.h>
using namespace std;

const int N1=11,N2=1e6+10;
int a[N1];
char b[N2];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	
	for(int i=0;i<s.size();i++){
		b[i]=s[i];
		if(b[i]>='0' && b[i]<='9'){
			a[b[i]-'0']++;
		}
	}
	
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout<<i;
		}
	}
	
	return 0;
} 
