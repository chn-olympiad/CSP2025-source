#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10; 
int a[N];
int num;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	string s2;
	cin>>s;
	int t=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[t]=s[i]-'0';
			t++;
		}
		
	}
	sort(a,a+t,cmp);
	
	for(int i=0;i<t;i++){
		cout<<a[i];
	}
	return 0;
}
