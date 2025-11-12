#include<bits/stdc++.h>
using namespace std;
string s;
int x=0,m,a[1005];
bool cmp(int q,int w){
	return q>w;
}
int main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   cin>>s;
    m=s.size();
   for(int i=0;i<m;i++){
    	if(s[i]>='0'&&'9'>=s[i]){
         a[x]=s[i]-48;
         x++;
     }
	}
	sort(a,a+x,cmp);
	for(int i=0;i<x;i++)
	cout<<a[i];
	return 0;
}