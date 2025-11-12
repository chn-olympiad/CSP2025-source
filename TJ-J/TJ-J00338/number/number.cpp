#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int pos=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[pos]=s[i]-'0';
			pos++;
		}
	}
	sort(a,a+pos,cmp);
	for(int i=0;i<pos;i++){
		cout<<a[i];
	}
	return 0;
}
