#include<bits/stdc++.h>
using namespace std;
int a[1000100],k;
string s;
bool cmp(int i,int j){
	return i>j;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i)
		if(s[i]>='0'&&s[i]<='9')a[k++]=s[i]-'0';
	sort(a,a+k,cmp);
	for(int i=0;i<k;++i)cout<<a[i];
	return 0;
}
