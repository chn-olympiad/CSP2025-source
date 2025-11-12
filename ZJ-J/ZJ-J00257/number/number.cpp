#include<bits/stdc++.h>
using namespace std;
string k;
int s[1000005],cnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>k;
	for(int i = 0;i<k.length();i++){
		if(k[i] >= 48 && k[i] <= 57){
			s[++cnt] = (int)k[i]-48;
		} 
	}
	sort(s+1,s+cnt+1,cmp);
	for(int i = 1;i<=cnt;i++){
		cout<<s[i];
	}
	return 0;
}
