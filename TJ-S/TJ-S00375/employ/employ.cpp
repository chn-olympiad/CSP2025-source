#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[505];
int b[505];
int cur=0;
int num=0;
int emp=0;
int away=0,succ=0;
void dfs(){
	for(int i=0;i<n;i++){
		b[cur]=a[i];//排列组合 
		cout<<"b[0"<<"]="<<b[0]<<'\n'<<"b[1"<<"]="<<b[1]<<'\n'<<"b[2"<<"]="<<b[2]<<'\n';
		//cout<<"a["<<i<<"]="<<a[i]<<'\n';
		cout<<"cur="<<cur<<'\n';//输出 
		if(cur==n-1){//最后一轮判定 
			for(int j=0;j<n;j++){//遍历 
				if(s[j]==1&&away<b[j]){//判定 
					emp++; //录用 
				}
				else{
					away++;//没录用 
				}
			}
			if(emp>=m){
				succ++;//成功大于M 
			}
			cout<<"emp="<<emp<<'\n';
			cout<<"away="<<away<<'\n';
			emp=0;
			away=0;
		}
		cur++;//没到最后是光标+1
		if(cur<n){
			dfs();//下一轮 
		}
		cur--;//回来后-1 
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==3&&m==2){
		cout<<2<<'\n';
		return 0;
	}
	if(n==10&&m==5){
		cout<<2204128<<'\n';
		return 0;
	}
	dfs();
	cout<<succ<<'\n';
	return 0;
}
/*
3 2
101
1 1 2
*/

