#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	int a[10];
	for(int i=0;i<10;i++)a[i]=0;
	cin>>n;
	for(int i=0;i<n.length();i++)if((n[i]>='0')*(n[i]<='9'))a[n[i]-'0']++;
	for(int i=9;i>=0;i--)while(a[i]>0){
		cout<<i;
		a[i]--;
	}
	return 0;
}
