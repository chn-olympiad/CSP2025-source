#include <bits/stdc++.h> 
using namespace std;
const int N=1e5+16;
int n;
int x1[N],x2[N],x3[N];
bool cmp(int a,int b){
	return a>b;
}
int baoli(int i,int a,int b,int c){
	if(a>n/2||b>n/2||c>n/2){
		return -0x3f3f3f;
	}
	if(i>n){
		return 0;
	}
	int ans=-1;
	ans=max(baoli(i+1,a+1,b,c)+x1[i],ans);
	ans=max(baoli(i+1,a,b+1,c)+x2[i],ans);
	ans=max(baoli(i+1,a,b,c+1)+x3[i],ans);
	return ans;
}
int main(){
	int t;cin>>t;
	bool A=true;
	for(int j=1;j<=t;j++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x1[i]>>x2[i]>>x3[i];
			if(x2[i]!=0||x3[i]!=0){
				A=false;
			} 
		}if(!A) cout<<baoli(1,0,0,0)<<endl;
		else{
			sort(x1+1,x1+n+1,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=x1[i];
			}cout<<ans<<endl;
		}
	}
	
}


/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1

4
0 1 0
0 1 0
0 2 0
0 2 0

2
10 9 8
4 0 0*/















