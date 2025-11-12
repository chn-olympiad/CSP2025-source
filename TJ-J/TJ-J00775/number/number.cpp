#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],l,cnt;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("number4.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(long long i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			a[cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(long long i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
}
