#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6;
string s;
int len;
int a[N],cnt;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=(s[i]-'0');
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<a[i];
	}
	return 0;
//	system("fc number4.out number4.ans");
}