#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int c[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
	cin>>s;
	n=s.size();
	s=' '+s;
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			c[s[i]-'0']++;
		}
	}
	int f=0;
	for(int i=9;i>=1;i--){
		for(int j=1;j<=c[i];j++){
			f=1;
			cout<<i;
		}
	}
	if(f){
		for(int i=1;i<=c[0];i++){
			cout<<0;
		}
	}else if(!f&&c[0]){
		cout<<0;
	}
	cout<<"\n";
	return 0;
}
