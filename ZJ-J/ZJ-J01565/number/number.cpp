#include<bits/stdc++.h>
using namespace std;
string s;
short a[1000002];long long l;
bool cmp(short x,short y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]<='9'&&s[i]>='0')a[++l]=s[i]-'0';
	sort(a+1,a+1+l,cmp);
	for(int i=1;i<=l;i++){
		cout<<a[i];
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
