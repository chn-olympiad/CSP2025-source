#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5; 
long long arr[N];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int xb=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			arr[i]=s[i]-'0';
		}else{
			xb++;
		}
	}
	sort(arr,arr+s.size());
	for(int i=s.size()-1;i>=xb;i--){
		cout<<arr[i];
	}
	return 0;
}
