#include<bits/stdc++.h>
using namespace std;
char a[10000000];
bool cmp(char c,char b){
	return c>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=1;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[cnt]=s[i];
			cnt++;
		}
	}
	
	sort(a+1,a+1+cnt,cmp);
	
	for(int i=1;i<=cnt;i++){
		cout<<a[i]; 
	}
	return 0;
	
} 
