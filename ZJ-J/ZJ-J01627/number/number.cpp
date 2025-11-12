#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[100000];
	for(int i=0;i<100000;i++){
		a[i]=-1;
	}
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[i]=s[i]-'0';
		}
	}
	sort(&a[0],&a[s.size()],cmp);
	for(int i=0;i<s.size();i++){
		if(a[i]!=-1){
			cout<<a[i];
		}
	}
	return 0;
}
