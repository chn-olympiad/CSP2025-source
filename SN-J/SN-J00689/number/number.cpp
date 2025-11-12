//SN-J00689  wangqikun  xi'anjiaodafuzhongchanbayouanxuexiao
#include "bits/stdc++.h"
using namespace std;
string s;
long long len,ans,idx=1,a[1000007];
bool cmp(int a,int b){ return a>b; }
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++) if(s[i]-'0'>=0&&s[i]-'0'<=9){ a[idx]=s[i]-'0'; idx++; }
	sort(a+1,a+idx+1,cmp);
	for(int i=1;i<idx;i++) cout<<a[i];
	return 0;
}
