#include<bits/stdc++.h>
using namespace std;
string s; 
int a[1000005],x=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>s;
	int l=s.size();
	if(l==1&&'0'<=s[0]&&'9'>=s[0]){
		cout<<s[0];
		return 0;
	}
	for(int i=0;i<=l-1;i++){
		if('0'<=s[i]&&'9'>=s[i]){
			a[x]=s[i]-'0';
			x++;
		}
	}
	sort(a+1,a+1+x,cmp);
	for(int i=1;i<=x-1;i++){
		cout<<a[i];
	}
	return 0;
}
