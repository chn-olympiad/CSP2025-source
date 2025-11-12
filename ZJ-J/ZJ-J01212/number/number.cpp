#include<bits/stdc++.h>
using namespace std;
string s;
int vis[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>s;
	for(int i=0;i<s.size();i++){
		int x=s[i]-'0';
		if(x<=9);
		vis[x]++;
	}
	int bk=0;
	for(int i=9;i>=1;i--){
		while(vis[i]--){
			cout<<i;
			bk++;
		}
	}
	if(bk!=0)while(vis[0]--)cout<<0;
	else cout<<0;
	return 0;
}

