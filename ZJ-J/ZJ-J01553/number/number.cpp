#include<bits/stdc++.h>
using namespace std;
int a[1000010],aid=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){ 
		if(s[i]>='0'&&s[i]<='9'){
			a[aid]=s[i]-'0';
			aid++;
		}
	}
	sort(a+1,a+aid,cmp);
	for(int i=1;i<aid;i++){
		cout<<a[i];
	}
	return 0;
}
