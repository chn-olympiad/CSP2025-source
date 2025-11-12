#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int n,a[N],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9')a[cnt++]=int(s[i]-'0');
	}
	sort(a,a+cnt);
	for(int i=cnt-1;i>=0;i--)cout<<a[i];
	return 0;
}
