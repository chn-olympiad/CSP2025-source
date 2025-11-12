#include<bits/stdc++.h>
using namespace std;
int num[10];
string s;
int main(){
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			num[s[i]-48]++;
	for(int i=9;i>=0;i--)
		while(num[i]){
			cout<<i;
			num[i]--;
		}
	return 0;
}
