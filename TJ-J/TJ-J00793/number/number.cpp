#include <bits/stdc++.h>
using namespace std;
string s,ans;
long long s1[1000005],cnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int lenth=s.size();
	for(int i=0;i<lenth;i++){
		if(s[i]>='0'&&s[i]<='9'){
			s1[i+1]=s[i]-'0';
			cnt++;
		}
	}
	sort(s1+1,s1+lenth+1,cmp);
	for(int i=1;i<=cnt;i++){
		ans+=(s1[i]+'0');
	}
	cout<<ans;
	return 0;
}
