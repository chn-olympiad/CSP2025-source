#include<bits/stdc++.h>
using namespace std;
string s;
long long l,a[1000001],sum;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(long long i=0;i<l;i++){
		if(s[i]=='0')a[i]=0,sum++;
		if(s[i]=='1')a[i]=1,sum++;
		if(s[i]=='2')a[i]=2,sum++;
		if(s[i]=='3')a[i]=3,sum++;
		if(s[i]=='4')a[i]=4,sum++;
		if(s[i]=='5')a[i]=5,sum++;
		if(s[i]=='6')a[i]=6,sum++;
		if(s[i]=='7')a[i]=7,sum++;
		if(s[i]=='8')a[i]=8,sum++;
		if(s[i]=='9')a[i]=9,sum++;
	}
	sort(a,a+l);
	for(long long i=l-1;i>=l-sum;--i)cout<<a[i];
	return 0;
}
