#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s,ss;
    cin>>s;
    for(int i=0;i<s.size();i++){
    	if(s[i]>='0'&&s[i]<='9'){
    		ss+=s[i];
		}
	}
	sort(ss.begin(),ss.end());
	reverse(ss.begin(),ss.end());
	cout<<ss;
	
    fclose(stdin);
    fclose(stdout);
	return 0;
}
