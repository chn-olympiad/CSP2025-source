#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int l,ans[100005]={0},n=0;
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans[n]=s[i]-'0';
			n++;
		}
	}
	sort(ans,ans+n,cmp);
	for(int i=0;i<n;i++){
		cout<<ans[i];
	}
	return 0;
}
