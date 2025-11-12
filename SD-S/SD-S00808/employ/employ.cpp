#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],c[505],s[505],b[505],ans;
char ch;
void check(){
	int cnt=0;
	for(int i=0;i<n;i++){
		if(c[b[i]]>s[i]){
			cnt++;
		}
	}
	(ans+=cnt>=m)%=998244353;
}
int main(){
	ifstream cin("employ.in");
	ofstream cout("employ.out");
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>ch;
		a[i]='1'-ch;
		b[i]=i;
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	partial_sum(a,a+n,s);
	do{
		check();
	}while(next_permutation(b,b+n));
	cout<<ans;
	return 0;
} 
