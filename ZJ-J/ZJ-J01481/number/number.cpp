#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000000+5;
const int inf=2147483647;
//
string s;
int a[MAXN];
int w=0;
//
bool cmp(int x,int y){
	return x>y;
}
//
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;++i){
		if(s[i]>='0'&&s[i]<='9'){
			a[++w]=s[i]-'0';
		}
	}
	sort(a+1,a+1+w,cmp);
	for(int i=1;i<=w;++i){
		printf("%d",a[i]);
	}
	return 0;
}