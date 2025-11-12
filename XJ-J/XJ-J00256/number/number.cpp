#include<bits/stdc++.h>
using namespace std;

string s;
long long int ii,ans[1500000];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long int len1=s.size();
	for(int i=0;i<len1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans[ii]=s[i]-48;
			ii++;
		}
	}
	sort(ans,ans+ii);
	for(int i=ii-1;i>=0;i--){
		cout<<ans[i];
	}
	return 0;
}

