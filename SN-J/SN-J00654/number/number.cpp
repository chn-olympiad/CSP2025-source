#include<bits/stdc++.h>
using namespace std;
int sn[1005];
string s;
int cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			sn[i]=int(s[i]-'0');
			cnt++;
		}
	}
	sort(sn+0,sn+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<sn[i];
	}
//char a=1;
//cout<<int(a);
	return 0;
}
