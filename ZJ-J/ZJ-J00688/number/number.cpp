#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[int(s[i]-'0')]++;
		}
	}
	int pan=0;
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			if(i!=0){
				pan=1;	
			}
			if(i==0&&pan==0){
				cout<<0;
				return 0;
			}
			for(int j=1;j<=a[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
