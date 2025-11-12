#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,a[N],num,ans,sum,maxn,minn;
string s,as;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++num]=(s[i]-'0');
		}
	}
	sort(a+1,a+1+num);
	for(int i=num;i>=1;i--){
		as=as+(char)(a[i]+'0');
	}
	cout<<as;
	return 0;
}//#Shang4Shan3Ruo6Shui4