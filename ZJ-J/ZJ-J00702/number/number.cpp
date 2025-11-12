#include <bits/stdc++.h>
using namespace std;
int n,i,j,f[1000010];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;n=s.size();
	for(i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9')
			f[s[i]-48]++;
	}
	for(i=9;i>=0;i--){
		for(j=1;j<=f[i];j++)
			cout<<i;
	}
	return 0;
}
