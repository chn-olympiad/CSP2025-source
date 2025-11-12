#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
string s;
ll ans[maxn],len;
bool f=false;
bool cmp(char a,char b){
	return a>b;
}
bool check(string s){
	for(int i=0;i<s.size();i++)
		if((s[i]>='0'&&s[i]<='9')&&s[i]!='0') return false;
	return true;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(check(s)){
		puts("0");
		return 0;
	}
	sort(s.begin(),s.end(),cmp);
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9') printf("%c",s[i]);
	return 0;
}
