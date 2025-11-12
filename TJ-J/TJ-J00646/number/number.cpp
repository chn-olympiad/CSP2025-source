#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	int sum=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int x=s[i]-'0';
			a[++sum]=x;
		}
	}
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++){
		cout<<a[i];
	}
	return 0;
}
//rp++ 
