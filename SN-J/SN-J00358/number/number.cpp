#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string j;
int s[N],cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>j;
	for(int i=0;i<j.size();i++){
		if(j[i]>='0'&&j[i]<='9'){
			s[cnt]=j[i]-'0';
			cnt++;
		}
	}
	sort(s,s+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<s[i];
	}
	return 0;
}
