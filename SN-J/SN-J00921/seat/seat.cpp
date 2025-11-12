#include<bits/stdc++.h>
using namespace std;
long long n,m,b[15][15],k,p,q;
struct stu{
	int vid,id;
}s[105];
bool cmp(stu a,stu b){
	return a.vid>b.vid;
}
int cnt=1;
void dfs(int x,int y){
	if(cnt==k){
		p=x;
		q=y;
		return;
	}
	if(y%2==1){
		if(x==n){
			cnt++;
			dfs(x,y+1);
		}
		else{
			cnt++;
			dfs(x+1,y);
		}
	}
	else{
		if(x==1){
			cnt++;
			dfs(x,y+1);
		}
		else{
			cnt++;
			dfs(x-1,y);
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i].vid;
		s[i].id=i;
	}
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(s[i].id==1){
			k=i;
		}
	}
	dfs(1,1);
	cout<<q<<" "<<p;
	return 0;
}

