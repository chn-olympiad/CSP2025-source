#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
string a; 
int d[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.length();
	for(int i=0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9'){
			d[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(d[i]){
			cout<<i;
			--d[i];
		}
	}
	return 0;
}

