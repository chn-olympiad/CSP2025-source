#include<bits/stdc++.h>
using namespace std;
int t[514];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)t[s[i]]++;
	for(int i='9';i>='0';i--){
		while(t[i]--)cout<<char(i);
	}
	cout<<endl;
	return 0;
}
//easy,delicious,miao
