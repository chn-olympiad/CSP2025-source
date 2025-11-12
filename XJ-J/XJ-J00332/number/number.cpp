#include<bits/stdc++.h>
using namespace std;
string s,d;
int len,f[10000000],l;
int g(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9')
		{
			l++;
			f[l]=s[i]-'0';
		}
	}
	sort(f+1,f+l+1,g);
	for(int i=1;i<=l;i++){
		cout<<f[i];
	}
	return 0;
}
