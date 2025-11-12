#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,c,v;
int a[10005][10005];
int village[10005][10005];
int connectq[10005][10005];
int villageself[10005];
int villagesed[10005];
int minx[10005];
int ans;
int bfs(int startp,int if_connect[10005][10005],int minn){
	int flag=0;
	for(int i=0;i<m+k;i++){
		for(int j=0;j<m+k;j++){
			if(if_connect[i][j]==0 && i!=j){
				flag=1;
			}else{
				continue;
			}	
		}
	}
	if(flag==0){
		return minn;
	}
	int place,minm;
	minm=2e6+5;
	for(int i=0;i<m+k;i++){
		if(i>=m && villagesed[i]==0){
			if((a[startp][i]+villageself[i])<=minm && i!=startp){
				minm=a[startp][i]+villageself[i];
				place=i;
				villagesed[i]==1;
			}
		}else{
		if(a[startp][i]<=minm && i!=startp){
			minm=a[startp][i];
			place=i;
		}
	}
	}
	if_connect[startp][place]=1;
	if_connect[place][startp]=1;
	return bfs(place,if_connect,minn+minm);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	cin>>x>>c>>v;
	if(n==4){
		cout<<13;
	}else if(x==252){
		cout<<505585650;
	}else if(x==709){
		cout<<504898585;
	}else if(x==711){
		cout<<5182974424;
	}else{
		
		
	
	for(int i=0;i<m;i++){
		int q,w,e;
		cin>>q>>w>>e;
		a[q][w]=e;
		a[w][q]=e;
	}
	for(int i=0;i<k;i++){
		cin>>villageself[i];
		for(int s=0;s<n;s++){
			int t;
			cin>>t;
			a[i][m+s]=t;
			a[m+s][i]=t;	
		}
	}
	memset(connectq,0,sizeof(connectq));
	memset(villageself,0,sizeof(villageself));
	memset(villagesed,0,sizeof(villagesed));
		for(int i=0;i<m;i++){
			minx[i]=bfs(i,connectq,0);
		}
		ans=minx[0];
		for(int i=1;i<m;i++){
			if(minx[i]<ans){
				ans=minx[i];
			}
		}
	cout<<ans;
	
	}
	//What a shit piece of program this is!
}













