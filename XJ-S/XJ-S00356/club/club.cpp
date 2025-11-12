#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,x;
	cin>>x;//组数 
	for(int j=0;j<x;j++){
		cin>>n;//人数 
		int h=0;
		int x=0;//部门 
		while(n>0){
		int a=0,b=0,c=0;
		cin>>a>>b>>c;
		h+=a;
		n--;
		}
		//输出 
		cout<<h<<endl;
	}
	return 0;
}
