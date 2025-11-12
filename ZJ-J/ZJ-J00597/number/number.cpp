#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
long long a[N];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.length();
	long long t=0;
	for(long long i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[t]=(long long)(s[i]-'0');
			t++;
		}
	}
	sort(a,a+t,cmp);
	for(long long i=0;i<t;i++){
		cout<<a[i];
	}
	cout<<endl;
	cout<<len<<endl;
	return 0;
}
