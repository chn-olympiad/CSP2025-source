#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen(".in","r",stdin)
freopen(".out","w",stdin)
string s,b;
int r,x,n,main=0;
cin>>s;
for(int i=0;i<=s;i++){
	if(s[i]<='9'&&s[i]>='0'){
	  n++;
	  b[i]=int(s[i]-'0');
	  }
	}
sort(b,b+n+1);
for(int i=0;i<=s;i++){
cout<<b[i];	
}
return 0;		
}


