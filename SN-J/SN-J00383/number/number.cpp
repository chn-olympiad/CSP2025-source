//SN-J00383 西安高新第二初级中学 初一 张源朔 
#include<bits/stdc++.h>

using namespace std;

string a;
long long len=0,x=1,b[1000005]={};

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	len=a.size();
	for(int i=0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[x]=a[i]-48;
			x++;
		}
	}
	sort(b+1,b+x);
	x--;
	for(int i=x;i>=1;i--){
		cout<<b[i];
	}
	return 0;
}
