#include<bits/stdc++.h>
using namespace std;
int tmp,f[1000005];
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			f[++tmp]=s[i]-'0';
		}
	}
	sort(f+1,f+tmp+1,cmp);
	for(int i=1;i<=tmp;i++)cout<<f[i];
}
