#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000010],n;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-48;
			n++;
		}
	}
	sort(a,a+s.length(),cmp);
	for(int i=0;i<n;i++)
		cout<<a[i];
	return 0;
}
