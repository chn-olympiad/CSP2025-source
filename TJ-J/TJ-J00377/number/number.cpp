#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
char a[1919810]="";
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i];
		}
	}
	sort(a,a+s.size(),cmp);
	cout<<a;
	return 0;
}
