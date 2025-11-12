#include<bits/stdc++.h>
using namespace std;
int dig[1000000],cnt=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","rw",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			dig[cnt]=(int)(s[i]-'0');
			cnt++;
		}
	}
	sort(dig+1,dig+cnt);
	if(dig[cnt-1]==0){
		cout<<0;
		return 0;
	}
	for(int i=cnt-1;i>0;i--){
		cout<<dig[i];
	}
	return 0;
}
/*I want to play Arcaea.
CCF give me 2200 mmr.
My Arcaea ID: 596 187 771*/
