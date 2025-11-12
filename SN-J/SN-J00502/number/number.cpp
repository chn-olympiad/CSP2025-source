#include<bits/stdc++.h>
using namespace std;
string st;
int num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>st;
	int siz=(int)st.size();
	for(int i=0;i<siz;i++){
		char c=st[i];
		int t=c-'0';
		if(0<=t&&t<=9){
			num[t]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++){
			cout<<i;
		}
	}
	return 0;
}
