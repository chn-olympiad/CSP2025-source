#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int maxx=0,f=0,cnt=0,t=0;
	for(int i=1;i<=s.size();i++){
		for(int j=0;j<=s.size()-1;j++){
			if(s[j]>='0'&&s[j]<='9'){
				if(maxx<s[j]-'0'){
					f=j;
					maxx=s[j]-'0';
					t=1;
				}
			} 
		}
		s[f]='a';
		if(t==1){
			cout<<maxx;
		}
		maxx=-1;
		t=0;
	}
	return 0;
}
