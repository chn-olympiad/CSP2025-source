#include<bits/stdc++.h>
using namespace std;
int a[1000000+10];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int p=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[p]=s[i]-'0';
			p++;
		}
	}
	sort(a,a+p,cmp);
	for(int i=0;i<p;i++){
		cout<<a[i];
	}
	return 0;
}
