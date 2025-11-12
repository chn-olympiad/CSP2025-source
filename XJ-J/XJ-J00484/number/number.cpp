#include<bits/stdc++.h>
using namespace std;
long long a[1000005]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long x=0;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[x]=s[i];
			x++;
		}
	}sort(a,a+s.size());
	string ans;
	for(long long i=s.size()-1;x>0;i--){
		x--;
		ans+=a[i];
	}cout<<ans;
	return 0;
}
