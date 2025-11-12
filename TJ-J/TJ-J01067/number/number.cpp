#include<bits/stdc++.h>
using namespace std;

string s;
char c[1000005];
int ind;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<int(s.size());i++){
		if('0'<=s[i]&&s[i]<='9')
			c[++ind]=s[i];
	}
	sort(c+1,c+ind+1);
	for(int i=ind;i>=1;i--){
		cout << c[i];
	}
	
	return 0;
} 
