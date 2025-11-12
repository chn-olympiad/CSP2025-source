#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],w,len;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			w++;
			a[w]=s[i]-'0';
		}
	}
	sort(a+1,a+w+1,cmp);
	if(a[w]==0||w==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=w;i++){
		cout<<a[i];
	}
	return 0;
}
