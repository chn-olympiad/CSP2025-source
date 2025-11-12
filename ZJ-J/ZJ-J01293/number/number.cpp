#include<bits/stdc++.h>
using namespace std;
int cnt[19]={0};
int main(){
	//freopen("number.in","r",stdin);
	freopen("1.txt","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	int f=1;
	for(int i=9;i>=0;i--){
		if(f&&i==0) break;
		for(int j=cnt[i];j>=1;j--){
			cout<<i;
			f=0;
		}
	}
	return 0;
}
