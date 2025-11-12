#include<bits/stdc++.h>
using namespace std;
#define int long long
char v[1000010];
bool cmp(char a,char b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >>s;
	int cnt=0;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			v[cnt]=s[i];
		}
	}sort(v+1,v+cnt+1,cmp);
	if(v[1]=='0')cout <<0;
	else{
		for(int i=1;i<=cnt;i++){
			cout <<v[i];
		}
	}
	return 0;
}

