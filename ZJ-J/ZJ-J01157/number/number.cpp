#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
string s;
int sl,al,a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	sl=s.size();
	for(int i=0;i<sl;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++al]=s[i]-'0';
		}
	}
	sort(a+1,a+al+1,greater<int>());
	for(int i=1;i<=al;i++){
		cout<<a[i];
	}
	return 0;
}
