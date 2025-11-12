#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll tong[15];
string a;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9'){
			tong[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<tong[i];j++){
			cout<<i;
		}
	}
	
	return 0;
}

