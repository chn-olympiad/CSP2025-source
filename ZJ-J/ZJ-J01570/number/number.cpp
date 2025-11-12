#include<bits/stdc++.h>
using namespace std;
string s;
const int maxn=1e6+5;
int a[maxn],cnt=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[++cnt]=int(s[i])-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	bool qiand=1;
	for(int i=1;i<=cnt;i++){
		if(a[i]!=0){
			qiand=0;
		}
		if(!(a[i]==0&&qiand==1&&i<=cnt-1)){
			cout<<a[i];
		}
	}
	return 0;
}