#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
struct node{
	int sc;
	bool isR;
}stu[N];
int n,m,cnt,r=1,c=1,f=1;
bool cmp(node a,node b){
	return a.sc>b.sc;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>stu[i].sc;
		if(i==1) stu[i].isR=1;
	}
	sort(stu+1,stu+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(stu[i].isR){
			cnt=i;break;
		}
	}
//	cout<<cnt;
	for(int i=1;i<=cnt;i++){
		if(i==cnt) break;
		if(r==n&&f==1) c++,f=-f,i++;
		else if(r==1&&f==-1) c++,f=-f,i++;
		if(i==cnt) break;
		r+=f;
	}
	cout<<c<<" "<<r;
	return 0;
}
