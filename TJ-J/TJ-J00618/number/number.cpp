#include<bits/stdc++.h>
using namespace std;
string s;
int a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[(s[i]-'0')%10]++;
	}
	for(int i=10;i>=0;i--)while(a[i]--) cout<<i; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
