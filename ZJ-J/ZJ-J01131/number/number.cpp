#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,a[20],l;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++)cout<<i;
	}
	cout<<endl;
	return 0;
}
