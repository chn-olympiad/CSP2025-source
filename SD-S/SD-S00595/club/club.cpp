#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
vector<int> s[10];
struct nn{
	int x,y,z,mx;
	int cx,cy,cz;
}a[N];
bool cmp(int xx,int yy){
	int p=min(a[xx].cy,a[xx].cz);
	int p2=min(a[yy].cy,a[yy].cz);
	return p<p2;
}
bool cmp2(int xx,int yy){
	int p=min(a[xx].cx,a[xx].cz);
	int p2=min(a[yy].cx,a[yy].cz);
	return p<p2;
}
bool cmp3(int xx,int yy){
	int p=min(a[xx].cy,a[xx].cx);
	int p2=min(a[yy].cy,a[yy].cx);
	return p<p2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].mx=max(a[i].x,max(a[i].y,a[i].z));
			a[i].cx=a[i].mx-a[i].x;
			a[i].cy=a[i].mx-a[i].y;
			a[i].cz=a[i].mx-a[i].z;
			ans+=a[i].mx;
			if(a[i].cx==0) s[1].push_back(i);
			if(a[i].cy==0) s[2].push_back(i);
			if(a[i].cz==0) s[3].push_back(i);
		}
		int len=s[1].size();
		int len2=s[2].size();
		int len3=s[3].size();
		if(len>n/2){
			sort(s[1].begin(),s[1].end(),cmp);
			for(int i=0;i<len-(n/2);i++){
				int k=s[1][i];
				ans-=min(a[k].cy,a[k].cz);
			}
		}
		if(len2>n/2){
			sort(s[2].begin(),s[2].end(),cmp2);
			for(int i=0;i<len2-(n/2);i++){
				int k=s[2][i];
				ans-=min(a[k].cx,a[k].cz);
			}
		}
		if(len3>n/2){
			sort(s[3].begin(),s[3].end(),cmp3);
			for(int i=0;i<len3-(n/2);i++){
				int k=s[3][i];
				ans-=min(a[k].cy,a[k].cx);
			}
		}
		cout<<ans<<"\n";
		s[1].clear();
		s[2].clear();
		s[3].clear();
		
	}
	return 0;
}


