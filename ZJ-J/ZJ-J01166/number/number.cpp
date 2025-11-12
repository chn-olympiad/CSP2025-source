#include<bits/stdc++.h>
using namespace std;
char s_[1000005];
int js_[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s_;
	for(int i=0; s_[i]!='\0'; i++){
		if(s_[i]>='0'&&s_[i]<='9'){
			js_[s_[i]-'0']++;
		}
	}
	for(int i=9; i>=0; i--){
		for(int j=1; j<=js_[i]; j++)cout<<i;
	}
	return 0;
}
