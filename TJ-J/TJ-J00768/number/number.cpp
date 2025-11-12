#include<bits/stdc++.h>
#include<cstdio>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pre(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;

string s;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	int len=s.size();
	rep(i,0,len-1) if(isdigit(s[i])) a[s[i]-'0']++;
	pre(i,9,0) while(a[i]) a[i]--,cout<<i;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}  
