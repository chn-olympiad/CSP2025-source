#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'

using namespace std;

typedef pair<int,int> PII;

bool cmp(int x,int y){
	return x>y;
}

const int N=1e6+10;
int a[N];

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	getline(cin,s);
	int idx=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			idx++;
			a[idx]=s[i]-'0';
		}
	}
	sort(a+1,a+idx+1,cmp);
	for(int i=1;i<=idx;i++){
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}