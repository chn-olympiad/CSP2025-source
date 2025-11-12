#include<bits/stdc++.h>
using namespace std;
string str;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>str;
	for(int i=0;i<str.size();i++)if(str[i]>='0'&&str[i]<='9')a[++a[0]]=str[i]-'0';
	sort(a+1,a+a[0]+1);
	for(int i=a[0];i>=1;i--)cout<<a[i];
	return 0;
}
