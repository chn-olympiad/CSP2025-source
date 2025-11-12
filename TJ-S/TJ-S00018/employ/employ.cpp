#include<bits/stdc++.h>
using namespace std;
string s;
unsigned long long numx=1;
int n,m,x,len,num,q,f;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","W",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x==1){
			q++;
		}
	}
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='1'){
			num++;
		}
		else if(f==0){
			f=i+1;
		}
	}
	for(int i=1;i<=n;i++){
		numx=numx*i;
	}
	if(n==num){
		cout<<numx<<endl;
	}
	else if(f>=m){
		cout<<numx<<endl;
	}
	else if(q==n){
		cout<<0<<endl;
	}
	else if(m>num){
		cout<<0<<endl;
	}
	else{
		cout<<numx<<endl;
	}
	return 0;
}
