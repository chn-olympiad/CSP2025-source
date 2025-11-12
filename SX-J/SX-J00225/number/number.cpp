#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int d[1005],b=-1,c,e=0;
	cin>>a;
	c=a.size()-1;
	for(int i=0;i<a.size();i++){
	if(a[i]>='0'&&a[i]<='9'){
		d[++b]=a[i]-'0';
		if(d[b])e++;
	}
	else c--;
	}
	if(e==0|c<0){
		cout<<0;
		return 0;
	}
	sort(d,d+b);
	for(int i=b;i>=0;i--)cout<<d[i];
	return 0;
}