#include<bits/stdc++.h>
using namespace std;
const int maxx=1e6+5;
int a[maxx];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=0;
	for(int i=0;i<s.size();i++){
			if(s[i]>='0'&&s[i]<='9'){
				l++;
				a[l]=int(s[i]-'0');
			}
	}
	sort(a+1,a+1+l,cmp);
	for(int i=1;i<=l;i++){
		cout<<a[i];
	}
	return 0;
}
