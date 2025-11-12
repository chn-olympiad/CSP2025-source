#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
struct node{
	int x,y;
}a[N],b[N];
map<int,int> mp;
int cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')
		  mp[s[i]-'0']++;
	}
	for(auto it=mp.begin();it!=mp.end();it++){
		int x=it->second,y=it->first;
		a[++cnt].x=y;
		a[cnt].y=x;
	}
	for(int i=cnt;i>=1;i--){
		while(a[i].y--)
		  cout<<a[i].x;
	}
	return 0;
}
/*

290es1q0
*/
