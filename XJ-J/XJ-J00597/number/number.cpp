#include<bits/stdc++.h>
using namespace std;
char n[1000100];
int vis[114];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	int len=strlen(n);
	for(int i=0;i<len;i++){
		if(n[i]>='0'&&n[i]<='9'){
			vis[n[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<vis[i];j++){
			cout<<i;
		}
	}
	return 0;
}
