//SN-J01085  闫卜予  西安高新一中沣东中学初中校区 

#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[20];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;	
}
