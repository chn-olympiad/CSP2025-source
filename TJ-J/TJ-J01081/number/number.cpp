#include<bits/stdc++.h>
using namespace std;
int a[1000010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ss="";
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=a[i]+(s[i]-'0');
			ss+=s[i];
		}
	}
	int ll=ss.size();
	sort(a,a+ll+1,cmp);
	for(int i=0;i<ll;i++)
		cout<<a[i];
	return 0;
}
