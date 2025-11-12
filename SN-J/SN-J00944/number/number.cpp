#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int a[maxn];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int num=0;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			num++;
		}
	}
	sort(a,a+len,cmp);
	for(int i=0;i<num;i++){
		cout<<a[i];
	}
	return 0;
}
