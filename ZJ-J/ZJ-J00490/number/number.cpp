#include<bits/stdc++.h>
using namespace std;
string s;
int arr[15];
bool flag;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			arr[s[i]-48]++;
		}
	}
	for(int i=10;i>=0;i--){
		if(i==0&&flag==0){
			cout<<0;
			return 0;
		}
		while(arr[i]){
			cout<<i;
			flag=1;
			arr[i]--;
		}
	}
}
