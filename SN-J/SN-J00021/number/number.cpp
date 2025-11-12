#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int t;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			t++;
			a[t]=(int)(s[i]-'0');
		}
	}
	sort(a+1,a+1+t,cmp);
	for(int i=1;i<=t;i++){
		cout<<a[i];
	}
	return 0;
}
