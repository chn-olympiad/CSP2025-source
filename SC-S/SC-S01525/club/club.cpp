#include<bits/stdc++.h>
using namespace std;

struct ss{
	int x,y,z;
}a[500005];

bool cmp1(int u,int v){
	return (a[u].x-max(a[u].y,a[u].z))>(a[v].x-max(a[v].y,a[v].z));
}

bool cmp2(int u,int v){
	return (a[u].y-max(a[u].x,a[u].z))>(a[v].y-max(a[v].x,a[v].z));
}

bool cmp3(int u,int v){
	return (a[u].z-max(a[u].y,a[u].x))>(a[v].z-max(a[v].y,a[v].x));
}

void cs(){
	vector<int> xx,yy,zz;
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
			xx.push_back(i);
			ans+=a[i].x;
		}
		else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
			yy.push_back(i);
			ans+=a[i].y;
		}
		else{
			zz.push_back(i);
			ans+=a[i].z;
		}
	}
	if(xx.size()>n/2){
		sort(xx.begin(),xx.end(),cmp1);
		for(int i=n/2;i<xx.size();i++){
			ans-=a[xx[i]].x-max(a[xx[i]].y,a[xx[i]].z);
		}
	}
	if(yy.size()>n/2){
		sort(yy.begin(),yy.end(),cmp2);
		for(int i=n/2;i<yy.size();i++){
			ans-=a[yy[i]].y-max(a[yy[i]].x,a[yy[i]].z);
		}
	}
	if(zz.size()>n/2){
		sort(zz.begin(),zz.end(),cmp3);
		for(int i=n/2;i<zz.size();i++){
			ans-=a[zz[i]].z-max(a[zz[i]].y,a[zz[i]].x);
		}
	}
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cs();
		cout<<'\n';
	}
	return 0;
}
