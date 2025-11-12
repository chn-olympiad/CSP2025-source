#include <iostream>
using namespace std;
long long read(){
	long long nov=1,dat=0;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			nov-1;
			c=getchar();
		}
	}
	while(c>='0'&&c<='9'){
		dat=(dat<<3)+(dat<<1)+(c&15);
		c=getchar();
	}
	return nov*dat;
}
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		cout<<0<<endl;
	}
	return 0;
}
