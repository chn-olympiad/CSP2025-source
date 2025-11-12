//考号:SN-J00425 姓名:强小轩 学校:渭南初级中学 
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ldb long double
using namespace std;
typedef pair<int,int> Pii;
string s;
vector<int> a;
bool cmp(int X,int Y){
	return X>Y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	int siz=(int)s.size();
	for(int i=0;i<siz;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin(),a.end(),cmp);
	if(a[0]==0){
		cout<<0<<'\n';
		return 0;
	}
	for(int i:a){
		cout<<i;
	}
	cout<<'\n';
	return 0;
}







































