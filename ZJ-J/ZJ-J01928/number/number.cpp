#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],j;
bool x(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[j++]=s[i]-'0';
		}
	}
	sort(a,a+j,x);
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
	return 0;
}
