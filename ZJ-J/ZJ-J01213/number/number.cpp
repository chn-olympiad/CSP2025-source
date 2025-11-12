#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000009];
int cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	s=' '+s;
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=cnt;i++) cout<<a[i];
	cout<<"\n";
	return 0;
}
