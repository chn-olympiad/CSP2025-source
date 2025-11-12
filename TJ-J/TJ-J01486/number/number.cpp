#include <bits/stdc++.h>
using namespace std;
int sz[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	int cnt=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0' and s[i]<='9'){
			sz[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(sz,sz+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<sz[i];
	}
	return 0;
} 
