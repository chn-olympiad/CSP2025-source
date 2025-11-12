#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
string s;
ll a[N],k=1;
ll ans=0;
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++) {
		if(s[i]>='0'&&s[i]<='9') {
			a[k]=s[i]-'0';
			k++;
		}
	}
	k--;
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++) {
		cout<<a[i];
	}
	return 0;
}
