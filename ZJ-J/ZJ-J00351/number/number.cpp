#include<iostream>
#include<algorithm>
using namespace std;
string s;
int a[1000006];
int idx;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(isdigit(s[i]))a[++idx]=(s[i]-48);
	}
	sort(a+1,a+1+idx,cmp);
	for(int i=1;i<=idx;i++)cout<<a[i];
	return 0;
}