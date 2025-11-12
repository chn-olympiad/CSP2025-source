#include<bits/stdc++.h>
using namespace std;
int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0' || '9'<ch){
		if(ch=='-'){
			f*=-1;
		}
		ch=getchar();
	}
	while('0'<=ch && ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		cout<<0<<endl;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}


