#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s,n;
bool flag;
int num[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			n+=s[i];
	for(int i=0;i<n.size();i++){
		if(n[i]!='0') flag=1;
	}
	if(!flag){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n.size();i++)
		num[i+1]=n[i]-'0';
	sort(num+1,num+n.size()+1);
	for(int i=n.size();i>=1;i--)
		cout<<num[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}