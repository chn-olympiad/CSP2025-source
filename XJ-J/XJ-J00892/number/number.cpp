#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int ss1=0;
char a[maxn];
bool cmp(char aa,char bb){
	return aa>bb;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]>='0' and s[i]<='9'){
			ss1++;
			a[ss1]=s[i];
		}
	}
	sort(a+1,a+1+ss1,cmp);
	for(int i=1;i<=ss1;i++){
		cout<<a[i];
	}
	return 0;
}//
