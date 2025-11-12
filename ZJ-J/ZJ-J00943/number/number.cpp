#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
string a;
int num[N],cnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(int(a[i])>=48 and int(a[i])<=57){
			num[++cnt]=int(a[i])-48;
		}
	}
	sort(num+1,num+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<num[i];
	}
	return 0;
}
