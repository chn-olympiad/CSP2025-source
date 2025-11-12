#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll a[1000005],n=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	s=' '+s;
	for(int i=1;i<=s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++n]=(int)s[i]-48;
		}
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	return 0;
}
/*
#Shang4Shan3Ruo6Shui4
*/