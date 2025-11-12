#include<bits/stdc++.h>
using namespace std;
string s;
long long a[15],ok;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int b=s[i]-'0';
			a[b]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0&&i!=0){
			ok=1;
		}
		if(i!=0){
			for(int j=1;j<=a[i];j++){
				cout<<i;
			}
		}
		else if(ok==1){
			for(int j=1;j<=a[i];j++){
				cout<<i;
			}
		}
		else{
			cout<<i;
		}
	}
	return 0;
}
