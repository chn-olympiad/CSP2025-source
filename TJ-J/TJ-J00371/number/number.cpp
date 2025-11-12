#include<iostream>
#include<cstring> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	bool sum=false;
	string a;
	int f[10]={0};
	cin>>a;
	for(int i=0;i<a.size();++i){
		if(a[i]>='0'&&a[i]<='9') f[a[i]-'0']++;
	}
	for(int i=9;i>0;--i) {
		if(f[i]>0){
			sum=true;
			break;
		}
	}
	if(sum)
	{
		for(int i=9;i>=0;--i){
			for(int j=f[i];j>0;--j) cout<<i;
		}
	}
	else cout<<0;
	return 0;
}
