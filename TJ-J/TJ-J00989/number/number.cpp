#include<bits/stdc++.h>
using namespace std;
#define N 1000005
char s[N];
int num[N];
int cnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=strlen(s);
	for(int i=n-1;i>=0;i--){
		s[i+1]=s[i];
	}
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[++cnt]=s[i]-'0';
		}
	}
	sort(num+1,num+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<num[i];
	}
	return 0;
} 
