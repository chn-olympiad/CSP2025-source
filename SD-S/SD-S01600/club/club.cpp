#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct st{
	int x,y;
}b[100005];
int T,n,a[100005][5],t[5];
bool cmp(st n,st m){
	return n.x-n.y>m.x-m.y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>n;
		t[0]=t[1]=t[2]=t[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])t[1]++;
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])t[2]++;
			else if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1])t[3]++;
		}
		int x=0;
		if(t[1]*2>n)x=1;
		else if(t[2]*2>n)x=2;
		else if(t[3]*2>n)x=3;
		if(x==0){
			ll s=0;
			for(int i=1;i<=n;i++)s+=max(a[i][1],max(a[i][2],a[i][3]));
			cout<<s<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			b[i].x=a[i][x];
			if(x==1)b[i].y=max(a[i][2],a[i][3]);
			if(x==2)b[i].y=max(a[i][1],a[i][3]);
			if(x==3)b[i].y=max(a[i][1],a[i][2]);
		}
		sort(b+1,b+n+1,cmp);
		ll s=0;
		for(int i=1;i*2<=n;i++)s+=b[i].x;
		for(int i=n/2+1;i<=n;i++)s+=b[i].y;
		cout<<s<<"\n";
	}
	return 0;
} 
