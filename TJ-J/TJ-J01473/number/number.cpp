#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[100005];
	long long b[10005]={},n=1,a=strlen(s);
	for(int i=1;i<=a;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
		    b[n]=s[1];
		    n++;
	    }
	}
	sort(b,b+n+1,cmp);
	for(int i=0;i<n;i++){
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
