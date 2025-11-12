#include<bits/stdc++.h>
using namespace std;
string s;
int n[1000001];
int cnt=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(int(s[i]-'0')>=0&&int(s[i]-'0')<=9) n[cnt++]=int(s[i]-'0');
	}
	cnt--;
	sort(n+1,n+1+cnt,cmp);
	for(int i=1;i<=cnt;i++) cout<<n[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

