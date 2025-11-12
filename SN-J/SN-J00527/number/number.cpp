#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000009];
bool cmp(int x,int y){
	return x>=y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cc=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cc]=s[i]-'0';
			cc++;
		}
	}
	sort(a,a+cc,cmp);
	for(int i=0;i<cc;i++){
		cout<<a[i];
	}
return 0;
}
