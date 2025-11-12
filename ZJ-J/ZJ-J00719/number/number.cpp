#include<bits/stdc++.h>
using namespace std;
string s;
const int N=1e6+10;
int num[N],tot;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)if(isdigit(s[i]))num[++tot]=s[i]-48;
	sort(num+1,num+tot+1,cmp);
	for(int i=1;i<=tot;i++)cout<<num[i];	
	return 0;
}
//I_Love_Furina