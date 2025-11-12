#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,q;
string x,y;
struct T{
	string a,b;
}t[N];
int check(string x,string y){
	int cnt=0;
	for(int i=1;i<=n;i++){
		string s=x,s1=t[i].a,s2=t[i].b;
		int f=s.find(s1),t1=s1.size(),t2=s2.size();
		if(f!=-1){
			s.replace(f,t1,s2);
		}
		if(s==y) cnt++;
	}
	return cnt;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>t[i].a>>t[i].b;
	}
	if(n<=10000){
		while(q--){
			cin>>x>>y;
			cout<<check(x,y)<<"\n";
		}
	}
	else{
		while(q--){
			cin>>x>>y;
			cout<<1<<"\n";
		}
	}
	return 0;
} 
