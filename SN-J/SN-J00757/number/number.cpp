#include<bits/stdc++.h>
using namespace std;
string s;
long long arr[1000009],a=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]<='9' && s[i]>='0'){
			arr[a]=s[i]-'0';
//			cout<<"ceshi:"<<arr[a]<<endl;
			a++;
		}
	}
	sort(arr+1,arr+a+1);
	for(int i=a;i>1;i--){
		cout<<arr[i];
	}
}
