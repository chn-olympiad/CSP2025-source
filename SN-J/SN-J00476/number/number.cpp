#include<bits/stdc++.h>
using namespace std;
string s;
int vis[10];
int p;
bool flag=false;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<s.size();i++){
		p=s[i]-'0';
		if(p>=0 && p<=9) vis[p]++;
	}
	for(int i=9;i>=0;i--){
		if(i!=0){
			if(vis[i]!=0) flag=true;
		}
		else{
			if(!flag){
				cout<<0;
				break;
			}
		}
		while(vis[i]!=0){
			cout<<i;
			vis[i]--;
		}
	}
	return 0;
}
