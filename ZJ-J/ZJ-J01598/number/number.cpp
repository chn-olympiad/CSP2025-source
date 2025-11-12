#include<bits/stdc++.h>
using namespace std;
long long book[100];
string st;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>st;
	for(int i=0;i<st.size();i++)
		if(st[i]>='0'&&st[i]<='9') book[st[i]-48]++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=book[i];j++) cout<<i;
}