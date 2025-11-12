#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='a'&&s[i]<='z'){
			s.erase(i,1);
			i--;
		}
	}
	for(int i=0;i<=s.size();i++){
		a[i]=s[i]-'0';
	}
	sort(a,a+s.size(),cmp);
	for(int i=0;i<s.size();i++){
		cout<<a[i];
	}
	return 0;
}
