/*李牧泽 SN-J00567 西安滨河学校*/
#include<bits/stdc++.h>
using namespace std;
#define FI(x) freopen(x".in","r",stdin)
#define FO(x) freopen(x".out","w",stdout)
char a[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	FI("number");
	FO("number");
	string s,x="";
	cin>>s;
	int j=0;
	for (int i=0;i<s.size();i++){
		if (s[i]>='0' and s[i]<='9'){
			a[j]=s[i];
			j++;
		}
	}
	sort(a,a+j,cmp);
	for (int i=0;i<j;i++){
		x+=a[i];
	}
	cout<<x;
	return 0;
}
