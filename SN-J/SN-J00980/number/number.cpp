// SN-J00980 谈子航  西安经开第二中学
#include<bits/stdc++.h>
using namespace std;
string s;
int d[1000010],n,ans;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='0' && s[i]<='9'){
			n++;
			if(s[i]=='1')d[i]=1;
			if(s[i]=='2')d[i]=2;
			if(s[i]=='3')d[i]=3;
			if(s[i]=='4')d[i]=4;
			if(s[i]=='5')d[i]=5;
			if(s[i]=='6')d[i]=6;
			if(s[i]=='7')d[i]=7;
			if(s[i]=='8')d[i]=8;
			if(s[i]=='9')d[i]=9;
		}
	}
	sort(d,d+n+1,cmp);
	for(int i=0;i<=n-1;i++)cout<<d[i];
 return 0;
}
