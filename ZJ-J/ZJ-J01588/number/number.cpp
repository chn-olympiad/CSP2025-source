#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
string s;
int cnt[15];
bool flag=0;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]<='9'&&s[i]>='0')
			cnt[s[i]-'0']++;
	for(int i=9;i>=0;i--){
		if(i!=0){
			for(int j=1;j<=cnt[i];j++)
				cout<<i;
			if(cnt[i])flag=1;
		}
		else{
			if(flag)
				for(int j=1;j<=cnt[i];j++)
					cout<<i;
			else cout<<"0"<<endl;
		}
	}
	return 0;
}
