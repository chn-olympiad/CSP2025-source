/*
CSP-J 
姓名：魏诺澜
准考证号：SN-J01196
学校：西北工业大学附属中学 
*/ 
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N],n;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9')a[++n]=s[i]-'0';
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)cout<<a[i];
	return 0;
}
