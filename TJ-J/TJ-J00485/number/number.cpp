#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s,c;
char d[1000007]; 
cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			c=c+s[i];
		}
	}
	for(int i=0;i<c.size();i++){
		d[i]=c[i];
	}
	int x=c.size();
	sort(d,d+x,cmp);
	for(int i=0;i<c.size();i++){
		cout<<d[i];
	}
	return 0;
}


