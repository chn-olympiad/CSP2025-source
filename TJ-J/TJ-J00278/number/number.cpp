#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int id;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	memset(a,-1,sizeof(a));
	for (int i=0;i<s.size();i++){
		 if (48<=s[i]&&s[i]<=57){
		 	a[id]=s[i]-48;
		 	id++;
		 } 
	}
	sort(a,a+s.size(),cmp);
	for (int i=0;i<s.size();i++){
		if (a[i]==-1){
			break;
		}
		cout<<a[i];
	}
	return 0;
} 
