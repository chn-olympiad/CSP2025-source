#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
string s,ans;
int n=0,num[maxn];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			n++;
			num[n]=s[i]-'0';
		}
	}
	sort(num+1,num+1+n,cmp);//cout<<num[i];
	for(int i=1;i<=n;i++) {
		ans+=char(num[i]+'0');
	}
	cout<<ans;
	return 0;
}
