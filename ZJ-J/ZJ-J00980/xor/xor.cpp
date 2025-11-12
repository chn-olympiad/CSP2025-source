#include<bits/stdc++.h>
using namespace std;

/*

9:24 开始看T3

9：55 确诊不会写，已经开始写骗分了，可以确定的是刚才半个小时最多只写出了十分
就是特殊性质A 

10:05 开始写dfs（特殊性质B）

10：32 正在爆炸 其实是调代码，但是爆炸了 

10：34 代码留档：

int a[500005];

int dfs_for_k_0(string s){
	int fzs=0;
	int i;
	int n=s.size();
	if(s[0]=='1'){
		for(i=0;i<n;i++){
			if(s[i]==1){
				i++;
				break;
			}
		}
		fzs++;
	}
	for(i;i<n;i++){
		if(s[i]==1) break;
		fzs++;
	}
	if(i==n){
		return fzs;
	}
	else{
		int next_0=i;
		while(a[next_0]==1) next_0++;
		return fzs+max(dfs_for_k_0(s.substr(i+1)),dfs_for_k_0(s.substr(next_0)));
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin>>n>>k;
	
	for(int i=0;i<n;i++) cin>>a[i];
	
	bool all_0_1=true;
	bool all_0=true;
	for(int i=0;i<n;i++){
		if(a[i]!=0&&a[i]!=1) all_0_1=false;
		if(a[i]!=0) all_0=false;
	}
	
	if(all_0==true){
		if(k==0) cout<<n;
		else cout<<0;
	}
	else if(all_0_1==true){
		string s="";
		for(int i=0;i<n;i++) s+=a[i]+'0';
		if(k==0){
			cout<<dfs_for_k_0(s);
		}
		else if(k==1){
			
		}
	}
	
	return 0;
}

10：38

算了，T3先放放，先写下T4的测试点1-3 

*/

int a[500005];

int dfs_for_k_0(string s){
	int fzs=0;
	int i;
	int n=s.size();
	if(s[0]=='1'){
		for(i=0;i<n;i++){
			if(s[i]==1){
				i++;
				break;
			}
		}
		fzs++;
	}
	for(i;i<n;i++){
		if(s[i]==1) break;
		fzs++;
	}
	if(i==n){
		return fzs;
	}
	else{
		int next_0=i;
		while(a[next_0]==1) next_0++;
		return fzs+max(dfs_for_k_0(s.substr(i+1)),dfs_for_k_0(s.substr(next_0)));
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin>>n>>k;
	
	for(int i=0;i<n;i++) cin>>a[i];
	
	bool all_0_1=true;
	bool all_0=true;
	for(int i=0;i<n;i++){
		if(a[i]!=0&&a[i]!=1) all_0_1=false;
		if(a[i]!=0) all_0=false;
	}
	
	if(all_0==true){
		if(k==0) cout<<n;
		else cout<<0;
	}
	else if(all_0_1==true){
		string s="";
		for(int i=0;i<n;i++) s+=a[i]+'0';
		if(k==0){
			cout<<dfs_for_k_0(s);
		}
		else if(k==1){
			
		}	
	}
	
	return 0;
}
