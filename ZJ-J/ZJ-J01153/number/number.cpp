#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000010];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int k=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++k]=s[i]-'0';
		}
	}
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<=k;i++){
		cout<<a[i];
	}
	
	return 0;
}
