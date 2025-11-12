#include<bits/stdc++.h>
using namespace std;
struct aaa{
	int x;
	int w;
};
vector<aaa>a[1005];
vector<aaa>b[15];
int cx[15];
void djstl(int x){
} 
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		a[x].push_back({y,w});
	}
	for(int i=1;i<=k;i++){
		cin>>cx[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			b[i].push_back({j,w});
		}
	}
	djstl(1);
}
