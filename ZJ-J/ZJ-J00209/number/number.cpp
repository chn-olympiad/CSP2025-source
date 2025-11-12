#include<bits/stdc++.h>
using namespace std;
string s;
int a[15];
bool flag=false;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]>0&&i!=0){
			for(int j=1;j<=a[i];j++){
				cout<<i;
			}
			flag=true;
		}
		else if(a[i]>0&&i==0){
			if(!flag) cout<<0;
			else{
				for(int j=1;j<=a[i];j++){
					cout<<i;
				}
			}
		}
	}
	return 0;
}
