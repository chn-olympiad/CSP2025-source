#include <bits/stdc++.h>
using namespace std;

int bucket[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++){
		char c=s[i];
		if('0'<=c&&c<='9') bucket[c-'0']++;
	}
	int now=9;
	while(now+1){
		if(bucket[now]){
			cout<<now;
			bucket[now]--;
		}
		else now--;
	}
	return 0;
}
