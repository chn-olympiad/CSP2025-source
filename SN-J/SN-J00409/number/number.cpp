#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size(),t=1;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[t]=s[i]-'0';
			t++;
		}
	}
	t--;
	sort(a+1,a+t+1);
	if(a[t]==0){
		cout<<0;
		return 0;
	}
	for(int i=t;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
