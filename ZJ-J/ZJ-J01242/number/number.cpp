#include<bits/stdc++.h>
using namespace std;
#define N 1001000
int a[N],cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<(int)s.size();++i){
		if(isdigit(s[i])){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>0;i--){
		cout<<a[i];
	}
	return 0;
}
