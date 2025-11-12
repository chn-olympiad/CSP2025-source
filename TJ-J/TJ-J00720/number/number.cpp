#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pre(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int N=1e6+5;
char a[N];
int num[50];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>(a+1);
	int len=strlen(a+1);
	rep(i,1,len){
		if('0'<=a[i]&&a[i]<='9') num[int(a[i]-'0')]++;
	}
	pre(i,9,0){
		while(num[i]!=0){
			cout<<i;
			num[i]--;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
