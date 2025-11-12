#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cnt=0,r;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		r=s[i]-'0';
		if(r>=0&&r<=9)
		{
			a[cnt]=r;
			cnt++;
		}
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
}