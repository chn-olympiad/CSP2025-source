#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x;//hang 
	long long y;//lie
};
int main(){
	long long n,m;
	cin>>n>>m;
	long long a=n*m;
	long long cj[a];
	for(long long i=0;i<a;i++){
		cin>>cj[i];
	}
	long long x=cj[0];
	long long p;
	sort(cj,cj+a);
	
	for(long long i=0;i<a;i++){
		if(cj[i]==x){
			p=a-i;
			break;
			
		}
	}
	//pÊÇÅÅÃû
	node ans;
	if(p%n==0){
		ans.x=p/n;
	}else{
		ans.x=p/n+1;
	}
	cout<<ans.x;
	if(ans.x%2==0){
		ans.y=n-(p%n)+1; 
	}else{
		if(p%n==0){
			ans.y=n;
		}else{
			ans.y=p%n;
		}
	}
	cout<<' '<<ans.y;
	return 0;
	}
