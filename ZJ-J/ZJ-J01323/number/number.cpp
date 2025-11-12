#include<bits/stdc++.h>
using namespace std;
string str;
int sum,a[1000010];
bool cmp(int i,int j){
	return i>j;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>str;
	int len=str.size();
	for(int i=0;i<len;i++)
		if(str[i]>='0'&&str[i]<='9') a[++sum]=str[i]-48;
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++) cout<<a[i];
	return 0;
}
