#include <bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	memset(a,0,sizeof a);
	cin >> s;
	bool k=false;
	for(int i=0;i<s.size();i++)if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
	for(int i=9;i>=0;i--){
		while(a[i]>0){
			a[i]--;
			cout << i;
			k=true;
		}
	}
	if(!k)cout << 0;
	return 0;
}//~100pts O(N)
