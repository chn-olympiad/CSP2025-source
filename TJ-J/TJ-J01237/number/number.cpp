#include<bits/stdc++.h>
using namespace std;

#define long long int
int a[1000001];
int b=0;
bool cmp(int c,int d){
	return c>d;
}

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
			a[b]=s[i]-'0';
			b++;
		}
	}
	sort(a,a+1+b,cmp);
	for(int i=0;i<b;i++)    cout<<a[i];
	
	return 0;
}
