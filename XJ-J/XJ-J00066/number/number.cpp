#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000001],n,g;
int flag=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for (int i=0;i<=s.size()-1;i++){
		if (s[i]>='0' && s[i]<='9'){
			a[i]=s[i]-'0';
			g++;
		}
		if (s[i]=='0'){
			flag=1;
		}
	}
	sort(a,a+s.size()-1,cmp);
	for (int i=0;i<=s.size()-1;i++){
		if (flag==1){
			if (a[i]==0){
				break;
			}
			cout<<a[i];
		}
		else{
			if (a[i]==0){
				n++;
			}
			if (n>g){
				break;
			}
			cout<<a[i];
		}
	}
	return 0;
} 
