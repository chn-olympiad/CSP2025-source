#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N],cnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+cnt+1,cmp);
	if(a[1]==0){
		printf("%d",0);
	}else{
		for(int i=1;i<=cnt;i++){
			printf("%d",a[i]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
