#include<bits/stdc++.h>

using namespace std;

int n;

int mp[15];

string s;

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	n=s.size();
	s=" "+s;
	
	for(int i=1;i<=n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			mp[int(s[i]-'0')]++;
		}
	}
	
	for(int i=9;i>=0;i--){
		for(int j=1;j<=mp[i];j++){
			printf("%d",i);
		}
	}
	
	return 0;
}