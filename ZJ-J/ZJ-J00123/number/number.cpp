#include<bits/stdc++.h>
using namespace std;
string s;
int a[20]; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","r",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	} 
	bool f=false;
	for(int i=10;i>=0;i--){
		for(int j=a[i];j>0;j--){ 
			if(i==0&&!f){
				cout<<i;
				break;
			}
			cout<<i;
			f=true;
		}
	}
	return 0;
} 
