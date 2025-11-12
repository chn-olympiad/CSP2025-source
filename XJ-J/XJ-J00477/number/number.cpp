#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int cnt;
int a[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48 && s[i] <= 57){
			cnt++;
			a[cnt]=s[i]-48;
		} 
	}
	sort(a+1,a+s.size()+1,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
} 
