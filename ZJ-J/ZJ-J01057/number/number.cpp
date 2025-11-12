#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
long long a[N],x=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[x]=s[i]-'0';
			x++;
		}
	}
	sort(a,a+1+x);
	if(a[x]==0)
		cout<<0;
	else{
		for(int i=x;i>=1;i--){
			cout<<a[i];
		}
	}
	return 0;
}

