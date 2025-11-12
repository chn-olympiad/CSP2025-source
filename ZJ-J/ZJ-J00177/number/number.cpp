#include<bits/stdc++.h>
using namespace std;
string a;
int k[1000005],flag=0,ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			flag++;
			k[flag]=a[i]-'0';
		}
	}
	sort(k+1,k+flag+1,cmp);
	for(int i=1;i<=flag;i++){
		ans=ans*10+k[i];
	}
	cout<<ans;
	return 0;
}
