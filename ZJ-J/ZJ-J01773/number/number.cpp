#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int l;
int a[1000005],b[15];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int sl=strlen(s);
	for(int i=0;i<sl;i++)a[i]=-1;
	for(int i=0;i<sl;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[++l]=s[i]-'0';
		}
	}
	sort(a+1,a+1+l,cmp);
	for(int i=1;i<=l;i++){
		if(a[i]==-1)continue;
		cout<<a[i];
	}
	return 0;
}
