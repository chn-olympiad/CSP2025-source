#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;
string st;
long long a[100100],k;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,st);
	for(int i=0;i<st.size();i++){
		if(st[i]>='0'&&st[i]<='9'){
			a[++k]=st[i]-'0';
		}
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
