#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string a;
int b[N],cnt;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9')b[cnt++]=a[i]-'0';
	}
	sort(b,b+cnt,cmp);
	for(int i=0;i<cnt;i++)printf("%d",b[i]);
	return 0;
}
