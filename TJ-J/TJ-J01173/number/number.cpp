#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=10000011;
string s;
ll a[N],j;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a,a+N,cmp);
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
	return 0;
}

