#include<bits/stdc++.h>
#define ll long long
#define N 15
using namespace std;

string s;
int c[N];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if('0'<=s[i]&&s[i]<='9')++c[s[i]-'0'];
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=c[i];j++)cout<<i;
	}
	return 0;
}
