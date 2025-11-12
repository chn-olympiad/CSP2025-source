#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
using namespace std;
int const M=1e6+10;
char c[M];
bool cmp(char a,char b){
    return a>b;
}
void solve(){
	string s;
    cin>>s;
    int k=1;
    for(int i=0;i<s.size();i++)if(isdigit(s[i]))c[k++]=s[i];
    sort(c+1,c+k+1,cmp);
    for(int i=1;i<=k;i++)cout<<c[i];
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("numder.out","w",stdout);
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}
