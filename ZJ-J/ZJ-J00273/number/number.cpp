#include<bits/stdc++.h>
using namespace std;
string s;
long long a[10000006],n=1;
bool cmp(long long x,long long y){
	if(x>y) return true;
	else return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i]-'0';
			n++;
		}
	}
	sort(a+1,a+n,cmp);
	if(n==1) cout<<0;
	else for(long long i=1;i<n;i++) cout<<a[i];
	cout<<endl;
	return 0;
}
