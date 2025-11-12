#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],num;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=(int)s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9') a[num++]=int(s[i])-48;
	}
	sort(a,a+num,cmp);
	for(int i=0;i<num;i++) cout<<a[i];
	return 0;
}
