#include<bits/stdc++.h>

//#define int long long
#define N 1000005
#define cint const int
using namespace std;
string s;
int a[N];
int tot=0;
bool cmp(cint &p,cint &q){
	return p>q;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[++tot]=(int)(s[i]-'0');
		}
	}
	sort(a+1,a+tot+1,cmp);
	for(int i=1;i<=tot;i++){
		cout<<a[i];
	}
	return 0;
}
/*
1 ≤ |s| ≤ 1e6



*/
/*
#Shang4Shan3Ruo6Shui4
*/