#include<bits/stdc++.h>
using namespace std;
int a[1000010],alen=1;
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[alen]=s[i]-'0';
			alen++;
		}
	}
	sort(a+1,a+alen,cmp);
	if(a[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<alen;i++){
		cout<<a[i];
	}
	return 0;
}
