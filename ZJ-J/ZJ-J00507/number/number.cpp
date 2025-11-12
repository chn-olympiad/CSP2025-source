#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
string s;
int a[1000001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int j1=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j1]=s[i]-'0';
			j1++;
		}
	}
	sort(a+1,a+j1,cmp);
	for(int i=1;i<=j1-1;i++){
		cout<<a[i];
	}
	return 0;
}