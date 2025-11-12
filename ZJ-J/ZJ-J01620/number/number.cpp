#include<bits/stdc++.h>
using namespace std;
long long a[10],f;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	    if(s[i]<='9'){
		    a[s[i]-'0']++;
		    if(s[i]!='0')f=1;
		}
    if(f==0){cout<<0;return 0;}
	for(int i=9;i>=0;i--)
	    for(int j=1;j<=a[i];j++)cout<<i;
}
