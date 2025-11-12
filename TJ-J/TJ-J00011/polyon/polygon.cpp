#include<bits/stdc++.h> 
#define ll long long
using namespace std;
const ll N=5*1e2+1;
const ll M=998244353;
int n,num;
ll a[N],b[N][N][N],c[N][N];
struct kk{
	ll number,ge,pd;
};
queue<kk>q;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n,cmp);
	if(a[0]+a[1]>=a[2]) cout<<1;
	return 0;
	q.push({a[0],1,1});
	q.push({0,0,1});
	for(int i=0;i<n;i++){
		for(int j=0;j<=pow(2,i);j++){
			int x=q.front().number,y=q.front().ge,z=q.front().pd;
			q.pop();
			q.push({x,y,z});
			if(y+1>=3&&x>=a[i]&&z){
				num=(num+1)%M;
				z=0;
			}
			q.push({x+a[i],y+1,z});
		}
	}cout<<num;
	
	return 0;
}
