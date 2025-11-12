#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
char a[1000010];
int cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int order=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')a[order]=s[i],order++;
	}
	sort(a,a+order,cmp);
	for(int i=0;i<order;i++)cout<<a[i];
	return 0;
}
