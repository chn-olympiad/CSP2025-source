#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<cstdlib>
using namespace std;
int read(){
	int dat=0,t=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')t=-t;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		dat=(dat<<1)+(dat<<3)+(ch&15);
		ch=getchar();
	}
	return dat*t;
}
string s;
int n,m,a[10]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,j;
	cin>>s;
	n=s.size();
	for(i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']+=1;
		}
	}
	for(i=9;i>=0;i--){
		while(a[i]>0){
			a[i]=a[i]-1;
			printf("%d",i);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

