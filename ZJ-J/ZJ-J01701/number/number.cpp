#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	int len=s.size();
	int cnt=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a,a+cnt,greater<int>());
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	return 0;
}
