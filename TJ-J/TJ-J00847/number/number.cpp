#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
typedef long long ll;
int num[20];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9') num[s[i]-48]++;
	for(int i=9;i>=0;i--) while(--num[i]>=0) cout<<i; 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
