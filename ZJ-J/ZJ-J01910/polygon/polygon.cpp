#include<bits/stdc++.h>
using namespace std;
int n;
int a[50005];
stack<int> q,p;
bool pd(){
	p=q;
	
	int len=q.size();
	if(len<3)return 0;
	long long num=0;
	long long thma=p.top();
	p.pop();
	for(int i=1;i<=len-1;i++){
		num+=p.top();
		//cout<<"p.front:"<<p.top()<<" ";
		p.pop();
	}
	//cout<<endl;
	
	num+=thma;
	//cout<<"max"<<thma<<endl;
	if(num>thma*2)return 1;
	return 0;
}
long long ans=0;
void dg(int deep){
	if(deep>n){
		if(pd())ans++;
		ans%=998244353;
		return ;
	}
	for(int i=0;i<=1;i++){
		
		if(i==1)q.push(a[deep]);
		//cout<<q.size()<<" "<<deep<<endl;
		dg(deep+1);
		if(i==1)q.pop();

	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dg(1);
	cout<<ans;
	return 0;
}