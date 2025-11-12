#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size(),arr[20]={0};
	bool zero=false;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			arr[s[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(i==0&&arr[0]!=0){
			if(zero!=true){
				cout<<'0';
				return 0;
			}
		}
		while(arr[i]>0){
			cout<<i;
			arr[i]--;
			zero=true;
		}
	}
	return 0;
}
