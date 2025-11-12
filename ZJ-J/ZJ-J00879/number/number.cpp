#include<bits/stdc++.h>
#define int long long 
using namespace std;
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sort(s.begin(),s.end());
	int f=1;
	for(int i=s.size()-1;i>=0;i--){
		if('0'<=s[i]&&s[i]<='9'){
			if(f==1&&s[i]=='0'){
				return cout<<0,0;
			}
			cout<<s[i];
			f=0;
		}
	}	
	return 0;
}