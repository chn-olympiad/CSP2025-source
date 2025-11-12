#include <bits/stdc++.h>
using namespace std;
string s;
int n[11]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]<='9'&&s[i]>='0')
			n[s[i]-'0']++;
	for(int i=9;i>=0;){
		if(n[i]!=0){
			printf("%d",i);
			n[i]--; 
		}else{
			i--;
		}
	}
	return 0;
}
