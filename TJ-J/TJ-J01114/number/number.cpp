#include <bits/stdc++.h>
using namespace std;
const int a=1e6+10;
int mp[a];
int main(){
	freopen("r","number.in",stdin);
	freopen("w","number.out",stdout);
	string s;
	cin>>s;
	int s2=0;
	
	for (int i=0;i<s.size();i++){
			if ('0'<=s[i] && s[i]<='9'){
				mp[s2]=s[i]-'0';
				s2++;
			}
	}
	for (int k=1;k<=s2-1;k++){
	
	for (int i=0;i<s2;i++){
		if (mp[i]<mp[i+1]){
			swap(mp[i],mp[i+1]);
		}
	}
}
	for (int i=0;i<s2;i++){
		printf("%d",mp[i]);
	}
			
	
	return 0;
}

