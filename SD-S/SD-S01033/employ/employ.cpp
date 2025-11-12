#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int read(){
	char ch=getchar();int k=0,f=1;
	if(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		k=k*10+(ch-'0');
		ch=getchar();
	}
	return k*f;
}
int n;
int a[N];
struct what{
	int id,minn;
	bool operator >(const what& x)const{
		return minn>x.minn;
	}
};
priority_queue<what,vector<what>,greater<what> > q;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();q.push(what{1,a[i]});
	}
	for(int i=1;i<=n;++i){
		what m=q.top();q.pop();
		cout<<m.minn<<endl;
	}
	
	return 0;
}
