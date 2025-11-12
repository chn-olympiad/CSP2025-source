#include<bits/stdc++.h>
using namespace std;
string s;
int vis[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9') vis[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(vis[i]){
			cout<<i;
			vis[i]--;
		}
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
