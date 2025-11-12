#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string s;
int num[10];
int main(){
    ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            num[s[i]-'0']++;
        }
	}
	for(short i=9;i>=0;i--){
        for(short j=0;j<num[i];j++){
            cout<<i;
        }
	}
	return 0;
}
