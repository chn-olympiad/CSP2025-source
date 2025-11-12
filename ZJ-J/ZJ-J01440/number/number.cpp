#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int N=1e6+10;
string s;
int ar[N];
int cnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){ 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>s;
	ll len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			ar[++cnt]=int(s[i]-'0');	
		}
	}
	sort(ar+1,ar+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<ar[i];
	}
	return 0;
}
