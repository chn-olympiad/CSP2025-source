#include<bits/stdc++.h>
using namespace std;
int q[1000005],cnt=-1;
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)
	    if(s[i]>='0'&&s[i]<='9'){
	    	cnt++;q[cnt]=s[i]-'0';
		}
	sort(q,q+cnt+1,cmp);
	for(int i=0;i<=cnt;i++)
	    cout<<q[i];
	return 0;
} 
