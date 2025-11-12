#include<bits/stdc++.h>
using namespace std;
string s;
int v[1000005];
int lens;
int cnt=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	lens=s.size();
	for(int i=0;i<lens;i++){
		if(s[i]>='0'&&s[i]<='9'){
			v[cnt]=int(s[i]-'0');
			cnt++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<cnt;j++){
			if(v[j]==i){
				cout<<i;
			}
		}
	}
	return 0;
}
