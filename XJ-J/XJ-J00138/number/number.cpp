#include<bits/stdc++.h>
using namespace std;
int b[15000000];
bool cmp(int aa,int bb){
	return aa>bb;
}
int main(){
	freopen("number1.in","r",stdin);
	freopen("number1.ans","w",stdout);
	string a;
	cin>>a;
	int len=a.length();
	for(int i=0;i<len;i++){
		if(a[i]<='9' and a[i]>='1'){
			b[i]=a[i];
		}
	}
	char j=0;
	sort(b+1,b+1+len,cmp);
	for(int i=0;i<=len-1;i++){
		j=char(b[i]);
		cout<<j;
	}
	return 0;
} 
