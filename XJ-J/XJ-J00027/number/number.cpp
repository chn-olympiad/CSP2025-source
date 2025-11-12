#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int l,vis[20];
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	l=a.size();
	for(int i=0;i<l;i++){
		
		if('0'<=a[i]&&a[i]<='9')
			vis[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
		for(int j=1;j<=vis[i];j++)
			cout<<i;
	return 0; 
}
