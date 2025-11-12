#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define PQ priority_queue
const int N=1e6+5;
int a[N],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')a[++cnt]=s[i]-'0';
	sort(a+1,a+1+cnt);
	if(a[cnt])
		for(int i=cnt;i>=1;i--)cout<<a[i];
	else cout<<0;
	return 0;
}
