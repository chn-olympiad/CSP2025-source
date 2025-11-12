#include<bits/stdc++.h>
using namespace std;
string s;
int a[11],ans=0;
bool flag=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[s[i]-'0']++;
			ans++;
		}
	}
	for(int i=9;i>=1;i--){
		while(a[i]>0){
			cout<<i;
			a[i]--;
			flag=1;
		}
	}
	if(flag==1){
		while(a[0]>0){
			cout<<0;
			a[0]--;
		}
	}else{
		cout<<0;
	}
	return 0;
}