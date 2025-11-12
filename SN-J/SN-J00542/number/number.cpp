#include<bits/stdc++.h> 
using namespace std;
const long long N=1e6+5;
long long a[N],b[N],ans=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		a[i]=0;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]>=48 && s[i]<=57){
			a[i]=int(s[i]-48);
			ans++;
		}else continue;
	}
	for(int i=0;i<s.size();i++){
		for(int j=0;j<s.size();j++){
			if(a[i]>a[j]) swap(a[i],a[j]);
		}
	}
	for(int i=0;i<ans;i++){
		cout<<a[i];
	}
	cout<<"\n";
	return 0;
}
