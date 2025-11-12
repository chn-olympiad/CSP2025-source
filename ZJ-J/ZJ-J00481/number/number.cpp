#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int b[1000010];
int k;
bool cmp(int s1,int s2){
	return s1>s2;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
    	if(s[i]>='0'&&s[i]<='9') b[++k]=s[i]-'0';
	}
	sort(b+1,b+1+k,cmp);
	if(b[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=k;i++){
		cout<<b[i];
	}
	return 0;
}
