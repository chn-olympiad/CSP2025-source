#include<bits/stdc++.h>
using namespace std;
string s;
int a[10005],n,j;
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=1;i<=n;i++){
		if(s[i]=='1'&&s[i]=='2'&&s[i]=='3'&&s[i]=='4'&&s[i]=='5'&&s[i]=='6'&&s[i]=='7'&&s[i]=='8'&&s[i]=='9'&&s[i]=='0'){
			a[j]=s[i]-'0';
			cout<<a[j];
			j++;
		}
	}
	return 0;
}
