#include<bits/stdc++.h>
using namespace std;
int a[10]={0,0,0,0,0,0,0,0,0,0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(a[i]>0){
			while(a[i]--){
				cout<<i;
			}
		}
	}
	return 0;
}
