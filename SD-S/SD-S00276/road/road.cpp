#include<bits/stdc++.h>
using namespace std;
int n,m,k,v,w,z,g;
long long sum,zb,wz;
map<long long,int>mm;
int a[100];
inline long long xy(int x,int y){
	return x*100000+y;
}
inline int xyx(long long in){
	return in%100000;
}
inline int xyy(long long in){
	return in/100000;
}
bool bl[10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>v>>w>>z;
		zb=xy(v,w);
		mm[zb]=z;
		zb=xy(w,v);
		mm[zb]=z;
	}
	for(int i=1;i<=k;i++){
		cin>>a[i];
		bl[i]=0;
		for(int j=1;j<=n;j++){
			cin>>z;
			z+=a[i];
			zb=xy(n+i,j);
			mm[zb]=z;
			zb=xy(n+i,j);
			mm[zb]=z;
		}
	}
	int mn;
	queue<long long> q;	
	for(int i=1;i<=n+k;i++){
		zb=xy(1,i);
		q.push(zb);
	}
	sum=0; 
	while(g<n){
		mn=1e9+1;
		for(int i=0;i<q.size();i++){
			if(mm[q.front()]){
				if(mm[q.front()]<mn){
					mn=mm[q.front()];
					q.push(wz);
					wz=q.front();
					q.pop();
				}
			}	
			q.push(q.front());
			q.pop();	
		}
		for(int i=1;i<=n+k;i++){
			zb=xy(xyy(wz),i);
			q.push(zb);
			}
		if(xyy(wz)>n){
			sum+=a[xyy(wz)-n]*bl[xyy(wz)-n];
			bl[xyy(wz)-n]=1;
		}
		sum+=mn;
		g++;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

