#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001],b,p;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s,b=s.size();
	for(int i=0;i<b;i++)if(s[i]>='0'&&s[i]<='9')a[p++]=(s[i]-48); 
	sort(a,a+p,cmp);
	for(int i=0;i<p;i++)cout<<a[i];
}
