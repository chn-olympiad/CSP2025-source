#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,xx,x,a=0,b=0,num=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","W",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		num=num+w;
	}
	for(int i=1;i<=k;i++){
		cin>>xx;
		if(xx==0) a++;
		for(int i=1;i<=n;i++){
			cin>>x;
			if(x==0) b++;
		}
	}
	if(a==k && b==k*n){
		cout<<0<<endl;
	}
	else{
		cout<<num<<endl;
	}
	return 0;
}
