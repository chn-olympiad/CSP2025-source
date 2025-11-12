#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct N{
	int x,id;
}a[100005][4];
int n;
bool cmp(N x,N y){
	return x.x>y.x;
}
int s[4]={0};
ll sm=0;
void f(int u){
	vector<int> x;
	for(int i=1;i<=n;i++){
		if(a[i][1].id==u){
			x.push_back(a[i][1].x-a[i][2].x);
		}
	}
	sort(x.begin(),x.end());
	for(int i=0;i<s[u]-n/2;i++){
		sm-=x[i];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		s[0]=s[1]=s[2]=s[3]=0,sm=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1].x,&a[i][2].x,&a[i][3].x);
			a[i][1].id=1,a[i][2].id=2,a[i][3].id=3;
			sort(a[i]+1,a[i]+4,cmp);
//			cout<<"--"<<a[i][1].x<<" "<<a[i][2].x<<" "<<a[i][3].x<<"\n";
			sm+=a[i][1].x;
			s[a[i][1].id]++;
		}
//		cout<<"-"<<sm<<"\n";
		if(s[1]>n/2){
			f(1);
		}else if(s[2]>n/2){
			f(2);
		}else if(s[3]>n/2){
			f(3);
		}
		cout<<sm<<"\n";
	}
	return 0;
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
4 0 0
*/
