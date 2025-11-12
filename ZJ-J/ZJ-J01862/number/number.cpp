#include<bits/stdc++.h> 
using namespace std;
const int N=1e6+10;
char c[N];
bool cmp(char a,char b){
	if(a==b){
		return false;
	}
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long len=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			c[len]=s[i];
			len++;
		}
	}
	sort(c,c+len,cmp);
	for(int i=0;i<len;i++){
		cout<<c[i];
	}
	return 0;
}
