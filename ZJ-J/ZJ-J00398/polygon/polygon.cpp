#include<bits/stdc++.h>
using namespace std;
long long P=0;
vector<long long>a;
void dfs(long long stepp,long long bian,deque<long long>tr){
	if(bian>=3){
		long long m=0,all=0;
		for(long long i=0;i<tr.size();i++){
			m=max(tr[i],m);
			all+=tr[i];
		}
		if(m*2<all){
			P++;
		}
	}
	stepp++;
	for(long long i=stepp;i<a.size();i++){
		tr.push_back(a[i]);
		dfs(i,bian+1,tr);
		tr.pop_back();
	}
	return;
}
int main(){
	ifstream cin("polygon.in");
	ofstream cout("polygon.out");
	long long n;
	cin>>n;
	a=vector<long long>(n+1);
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,{});
	cout<<P%998244353<<endl;
}
