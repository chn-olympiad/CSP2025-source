#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],tot;
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++){if(isdigit(s[i]))a[++tot]=s[i]-'0';}
	sort(a+1,a+1+tot,cmp);
	for(int i=1;i<=tot;i++)cout<<a[i];
	return 0;
} 
