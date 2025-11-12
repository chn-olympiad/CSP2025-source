#include<bits/stdc++.h>
using namespace std;
const int N=1000005; 
string s;
int n[N],top=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.size();i++)
		if (s[i]>='0' && s[i]<='9')
			n[top++]=s[i]-'0';
	sort(n+1,n+top,cmp);
	if (n[1]==0)
		cout<<0;
	else
		for (int i=1;i<top;i++)
			cout<<n[i];
	return 0;
}
