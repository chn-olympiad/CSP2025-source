#include<bits/stdc++.h>
using namespace std;
int x[10000]={},lon[100000];
string s[100000][1000000]={},yhhs[1000000]={};
int n=1;
int ejz(int a){
	int len=1,l[1000000];
	if(a%2==1) l[1]=1;
	else l[1]=0;
	while(a>1){
		++len;
		if(a/2%2==1){
			l[len]=1;
			a/=2;
		}
		else{
			l[len]=0;
			a/=2;
		}
	}
	for(int i=1;i<=len;i++)
	   s[n][i]=l[i];
	lon[n]=len   
}
int yhh(int a,int b){
	for(int i=1;i<=max(lon[a],lon[b]);i++){
		if(s[a][i]==s[b][i]) yhhs[i]=0;
		else yhhs[i]=1;
	}
}
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
    long long n,k;
    for(int i=1;i<=n;i++){
    	cin>>x[i];
    	ejz(x[i]);
    	n++;
	}
	
	return 0;
}
