#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string str;
int cnt,ans,a[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++)
	   if(str[i]<='9'&&str[i]>='0')
	      cnt++,a[cnt]=str[i]-'0';
	stable_sort(a+1,a+1+cnt);
	for(int i=cnt;i>0;i--) cout<<a[i];
	return 0;
}  

