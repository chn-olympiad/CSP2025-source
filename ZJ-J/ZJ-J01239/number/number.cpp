#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000010];
int cnt;
bool px(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[++cnt]=s[i];
		}
	}
	sort(a+1,a+1+cnt,px);
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdin);
	return 0;
}
