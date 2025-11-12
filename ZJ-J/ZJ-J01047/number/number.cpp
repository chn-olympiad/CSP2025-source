#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[20];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(auto i:s){
		if(isdigit(i)){
			a[i-'0']++;
		}
	}
	int flag=0;
	for(int i=9;i>=1;i--){
		while(a[i]){
			flag=1;
			cout<<i;
			a[i]--;
		}
	}
	if(flag==0){
		if(a[0]){
			cout<<0;
		}
	}
	else{
		while(a[0]){
			flag=1;
			cout<<0;
			a[0]--;
		}
	}
}
