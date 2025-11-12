#include<bits/stdc++.h>
using namespace std;
#define N 1000005

string s; 
int a[N],cnt=0;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.length();++i){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	} 
	sort(a,a+s.length(),cmp);
	for(int i=0;i<cnt;++i){
		cout<<a[i];
	}
	return 0;
}
