#include<bits/stdc++.h>
#define int long long
#define ioi ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
using namespace std;
string s;
int a[10],ll;
signed main(){
	ioi;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	s=" "+s;
	for(int i=1;i<=l;i++)if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
	if(a[0]>0&&a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0&&a[6]==0&&a[7]==0&&a[8]==0&&a[9]==0){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--)for(int j=1;j<=a[i];j++) cout<<i;
	return 0;
}