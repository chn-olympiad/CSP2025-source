#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int m=s.size();
	int cnt=0;
	for(int i=0;i<m;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,greater<int>());
	for(int i=1;i<=cnt;i++)cout<<a[i];
	cout<<endl;
	return 0;
}
