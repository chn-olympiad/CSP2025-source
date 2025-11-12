#include<bits/stdc++.h>
using namespace std;
string str,sx;
int mp[10];
bool x;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0' && str[i]<='9'){
			mp[str[i]-'0']++;
		}
	}
	for(int i=9;i>=1;i--){
		if(mp[i]!=0){
			x=true;
			while(mp[i]){
				sx+=char(i+'0');
				mp[i]--;
			}
		}
	}
	if(!x){
		cout<<"0";
		return 0;
	}
	else{
		while(mp[0]){
			sx+='0';
			mp[0]--;
		}
	}
	cout<<sx;
	return 0;
}
