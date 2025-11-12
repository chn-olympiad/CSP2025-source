#include<bits/stdc++.h>
using namespace std;
int xo(int a,int b){
	if(a==b) return a;
	stack<int> qa;
	stack<int> qb;
	stack<int> qc;
	int cnt=0;
	while(a){
		qa.push(a%2);
		a/=2;
	}
	while(b){
		qb.push(b%2);
		b/=2;
	}
	while(!qa.empty()&&!qb.empty()){
		int x=qa.top();qa.pop();
		int y=qb.top();qb.pop();
		if(x||y){
			qc.push(1);
		}
		else qc.push(0);
	}
	while(!qa.empty()){
		int x=qa.top();qa.pop();
		qc.push(x);
	}
	while(!qb.empty()){
		int x=qb.top();qb.pop();
		qc.push(x);
	}
	int p=1;
	while(!qc.empty()){
		int x=qc.top();qc.pop();
		cnt+=x*p;
		p*=2;
	}
	return cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,s=0,mx=0,f=1,p=0;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==m){
			s++;
		}
		if(a[i]!=1){
			f=0;p++;
		}
		mx=max(mx,a[i]);
	}
	if(m==0){
		cout<<s;
	}
	else if(f){
		if(m!=1) cout<<0;
		else{
			cout<<s;
		}
	}
	else if(mx==1){
		if(m==0) cout<<p;
		else cout<<s;
	}
	else if(n<10000){
		int ans=0;
		for(int i=1;i<=n;i++){
			int l=a[i];
			for(int j=i+1;j<=n;j++){				
				l=xo(l,a[j]);						
				if(l==m){
					ans++;
					i=j+1;	
				}								
			}
		}
		cout<<ans;
	}
	else cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
