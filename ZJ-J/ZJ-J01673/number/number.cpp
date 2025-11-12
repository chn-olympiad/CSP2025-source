#include <bits/stdc++.h>
using namespace std;
int arr[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	int s=0;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9'){
			s++;
			arr[s]=str[i]-'0';
		}
	}
	sort(arr+1,arr+s+1);
	if(arr[s]==0){
		cout<<0;
		return 0;
	}
	for(int i=s;i>=1;i--){
		cout<<arr[i];
	}
	return 0;
}