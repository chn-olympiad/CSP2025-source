#include<bits/stdc++.h>
using namespace std;
string st;
long long a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>st;
	memset(a,0,sizeof(a));
	for(int i=0;i<st.size();i++)
		if(st[i]>='0'&&st[i]<='9')
			a[st[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(long long j=1;j<=a[i];j++)
			cout<<i;
	return 0;
}
