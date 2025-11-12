#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
int t,n,c1,c2,c3;
int f1[N];
int f2[N];
int f3[N];
int a[N][4];
bool cmp1(int x,int y){
	return (a[x][1]-max(a[x][2],a[x][3]))>(a[y][1]-max(a[y][2],a[y][3]));
}
bool cmp2(int x,int y){
	return (a[x][2]-max(a[x][1],a[x][3]))>(a[y][2]-max(a[y][1],a[y][3]));
}
bool cmp3(int x,int y){
	return (a[x][3]-max(a[x][2],a[x][1]))>(a[y][3]-max(a[y][2],a[y][1]));
}
void Clear(){
	c1=c2=c3=0;
	for(int i=1;i<=c1;i++)
		f1[i]=0;
	for(int i=1;i<=c2;i++)
		f2[i]=0;
	for(int i=1;i<=c3;i++)
		f3[i]=0;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		Clear();
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
				f1[++c1]=i;
			else if(a[i][2]>=a[i][3]&&a[i][2]>=a[i][1])
				f2[++c2]=i;
			else
				f3[++c3]=i;
		}
		sort(f1+1,f1+c1+1,cmp1);
		sort(f2+1,f2+c2+1,cmp2);
		sort(f3+1,f3+c3+1,cmp3);
		while(c1>n/2){
			if(a[f1[c1]][2]>=a[f1[c1]][3])
				f2[++c2]=f1[c1];
			else
				f3[++c3]=f1[c1];
			c1--;
		}
		while(c2>n/2){
			if(a[f2[c2]][1]>=a[f2[c2]][3])
				f1[++c1]=f2[c2];
			else
				f3[++c3]=f2[c2];
			c2--;
		}
		while(c3>n/2){
			if(a[f3[c3]][1]>=a[f3[c3]][2])
				f1[++c1]=f3[c3];
			else
				f2[++c2]=f3[c3];
			c3--;
		}
		int ans=0;
		for(int i=1;i<=c1;i++)
			ans+=a[f1[i]][1];
		for(int i=1;i<=c2;i++)
			ans+=a[f2[i]][2];
		for(int i=1;i<=c3;i++)
			ans+=a[f3[i]][3];
		cout<<ans<<'\n';
	}
	return 0;
}