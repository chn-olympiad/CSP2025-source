#include<bits/stdc++.h>
using namespace std;
int a[1000001];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int k = 0;
	for(int i = 0;i < s.size();i++){
		if(s[i] <= '9' && s[i] >= '0'){
			a[++k] = s[i]-'0';
		}
	}
	sort(a+1,a+k+1,cmp);
	for(int i = 1;i <= k;i++)
		cout<<a[i];
	return 0;
}