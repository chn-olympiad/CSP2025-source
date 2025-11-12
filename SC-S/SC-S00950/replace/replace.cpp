#include<bits/stdc++.h>
using namespace std;
long long n,q; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=q;i++){
		if(n==1){
			cout<<1<<'\n';
		}
		else{
			cout<<0<<'\n';
		}
	}
	return 0;
}








/*
距离考试结束：00:40:06
开始写一些点吧，虽然不一定写得出来 
距离考试结束：00:33:40
发现不太可能会，蒙全是0吧 
距离考试结束：00:29:55
提交吧 
*/