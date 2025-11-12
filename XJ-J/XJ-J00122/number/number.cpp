#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N],w=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[w]=s[i]-'0';
			w++;
		}
	}
	sort(a,a+s.size(),cmp);
	for(int i=0;i<w;i++){
		cout<<a[i];
	}
	return 0;
} 
