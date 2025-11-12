#include<bits/stdc++.h>
using namespace std;
string s;
int n,a[10]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cout.tie(0),cin.tie(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(a[i]>=0){
			for(int j=0;j<a[i];j++)cout<<i;
		}
	}
	return 0;
  
}
