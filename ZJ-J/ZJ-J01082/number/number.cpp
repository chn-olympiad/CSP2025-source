#include<bits/stdc++.h>
using namespace std;
string s;
int n;
char c[1000005];
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	s='0'+s;
	for(int i=1;i<=n;i++){
		c[i]=s[i];
	}
	sort(c+1,c+n+1,cmp);
	int i=1;
	for(int i=1;i<=n;i++){
		if(c[i]>='0' && c[i]<='9')cout<<char(c[i]);
	}
}