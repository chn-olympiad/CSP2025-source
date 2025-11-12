#include<bits/stdc++.h>
using namespace std;
int n[15],f=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int len=a.size();
	for(int i=0;i<=len;i++){
		if(a[i]>='0'&&a[i]<='9') n[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(i==0&&a[i]!=0&&f==0){
			cout<<"0";
			return 0;
		}
		while(n[i]>0){
			f=1;
			cout<<i;
			n[i]--;
		}
	}
	
	return 0;
}