#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int l,cnt;
vector<int> num;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.length();
	for(int i=0;i<l;i++){
		if('0'<=s[i]&&s[i]<='9'){
			num.push_back(s[i]-'0');
			cnt++;
		}
	}
	sort(num.begin(),num.end());
	for(int i=cnt-1;i>=0;i--){
		cout<<num[i];
	}
	return 0;
}
