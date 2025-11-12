#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
vector<int>arr;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i] and s[i]<='9'){
			arr.push_back(s[i]-'0');
		}
	}
	sort(arr.begin(),arr.end(),greater<int>());
	for(int i=0;i<arr.size();i++){
		printf("%d",arr[i]);
	}
	return 0;
}