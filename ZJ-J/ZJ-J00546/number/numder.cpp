#include<bits/stdc++.h>
using namespace std;
string s;
void solve(int x){
    for(int i=0;i<s.size();i++){
	    if(s[i]-'0'==x){
	    	cout<<s[i];
	    }
	}
	return;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=9;i>=0;i--){
		solve(i);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}//O(n)
