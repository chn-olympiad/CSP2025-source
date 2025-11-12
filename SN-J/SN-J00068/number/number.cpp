#include<bits/stdc++.h>
using namespace std;
string s;int a[1000010],g=0;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	s='0'+s;
	for(int i=1;i<=l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++g]=s[i]-'0';
		}
	}
	sort(a+1,a+g+1,cmp);
	for(int i=1;i<=g;i++){
		cout<<a[i];
	}
	return 0;
} 
