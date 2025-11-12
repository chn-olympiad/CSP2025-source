#include<bits/stdc++.h>

using namespace std;
int a[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string s;
	int len=0;
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++len]=s[i]-'0';
		}
	}
	sort(a+1,a+1+len,cmp);
	for(int i=1;i<=len;i++){
		cout << a[i];
	}
	return 0;
}
