#include<bits/stdc++.h>
using namespace std;
int main{
	freopen("number.in","r",stdin)
	freopen("number.out","w",stdout)
	int s[8];
	int i,ans=0;
		for(i=0;i<s;i++)cin<<s[8];
		for(i=0;i<s;i++){ 
			ans=max(s[i]+s[(i+1)%n]+s[(i+2)%n]+s[(i+3)%n]);	
		}
	cout<<ans;
	return 0;
}
