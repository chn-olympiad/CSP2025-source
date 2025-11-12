#include<bits/stdc++.h>
#define LANH using
#define AK namespace
#define CSPJ std
LANH AK CSPJ;
typedef long long ll;
int vis[109];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char c:s){
		if(c<='9'){
			vis[c-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(vis[i]){
			cout<<i;
			vis[i]--;
		}
	}
	return 0;
}

