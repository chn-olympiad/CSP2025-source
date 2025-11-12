#include <bits/stdc++.h>
#include <cstdio>
#define int long long
using namespace std;

string str;
int num[1000000];

int sortn(int a,int b){
	return a>b;
}


signed main(){
	
	//sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	
	cin>>str;
	
	int n=0;
	for(int i=0;i<str.size();i++){
		
		int nnum=str[i];
		
		if(nnum<=87&&nnum<=97){
			nnum-=48;
		}

		if(0<=nnum && nnum<=9){
			//cout<<nnum;
			num[n]=nnum;	
			n++;
		}
		
	}
	
	sort(num,num+n,sortn);
	
	//cout<<'\n';
	for(int i=0;i<n;i++){
		cout<<num[i];
	}

	return 0;
	
}
