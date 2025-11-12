#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
string s;
int tot,a[maxn];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++tot]=s[i]-'0';
		}
	}
	sort(a+1,a+1+tot,cmp);
	for(int i=1;i<=tot;i++){
		cout<<a[i];
	}
	return 0;
}
