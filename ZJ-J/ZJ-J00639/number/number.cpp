#include<bits/stdc++.h>
using namespace std;
const int MAXS=1e6+10;
string s;
int num[MAXS]/*jilu*/,l=0/*num.size*/;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') num[++l]=s[i]-'0';
	}
	sort(num+1,num+l+1,cmp);
	for(int i=1;i<=l;i++){
		cout<<num[i];
	}
	return 0;
}
