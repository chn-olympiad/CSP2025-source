#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number","r",stdin);
	freopen("number","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	int a[1000005];
	for(int i=0;i<s.length();i++){
		if(s[i]>='1'&&s[i]<='9'){
			a[i]=s[i];
		}
	}
	for(int i=0;i<s.length();i++){
		int max=0;
		for(int j=i;j<s.length();i++){
			if(a[j]>=max){
				max=a[j];
			}
		}
		cout<<max;
	}
	return 0;
}
