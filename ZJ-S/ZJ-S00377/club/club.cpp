#include<bits/stdc++.h>
using namespace std;
int T,n;
bool b[100005];
struct node{
	int x[4];
	int ma,mid;
}a[100005];
struct node2{
	int x,y;
};
bool cmp(node2 x,node2 y){
	return x.x>y.x||x.x==y.x&&x.y<y.y;
}
bool tepan1(){
	int s=0;
	for(int i=1;i<=n;i++)
	if(a[i].x[2]!=0||a[i].x[3]!=0)return 0;
	else s+=a[i].x[1];
	cout<<s;
	return 1;
}
bool tepan2(){
	node2 c[100005];
	int s=0,ma=-1;
	for(int i=1;i<=n;i++)
	if(a[i].x[3]!=0)return 0;
	else c[i].x=a[i].x[1],c[i].y=a[i].x[2];
	sort(c+1,c+n+1,cmp);
	for(int i=n/2;i>=1;i--)s+=c[i].x;
	for(int i=n/2+1;i<=n;i++)s+=c[i].y;
	ma=max(ma,s);s=0;
	for(int i=1;i<=n;i++)c[i].x=a[i].x[2],c[i].y=a[i].x[1];
	sort(c+1,c+n+1,cmp);
	for(int i=n/2;i>=1;i--)s+=c[i].x;
	for(int i=n/2+1;i<=n;i++)s+=c[i].y;
	ma=max(ma,s);
	cout<<ma;
	return 1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		int ma=INT_MIN;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x[1]>>a[i].x[2]>>a[i].x[3];
			if(a[i].x[1]>=a[i].x[2]&&a[i].x[2]>=a[i].x[3])a[i].ma=1,a[i].mid=2;
			else if(a[i].x[1]>=a[i].x[3]&&a[i].x[3]>=a[i].x[2])a[i].ma=1,a[i].mid=3;
			else if(a[i].x[2]>=a[i].x[1]&&a[i].x[1]>=a[i].x[3])a[i].ma=2,a[i].mid=1;
			else if(a[i].x[2]>=a[i].x[3]&&a[i].x[3]>=a[i].x[1])a[i].ma=2,a[i].mid=3;
			else if(a[i].x[3]>=a[i].x[1]&&a[i].x[1]>=a[i].x[2])a[i].ma=3,a[i].mid=1;
			else if(a[i].x[3]>=a[i].x[2]&&a[i].x[2]>=a[i].x[1])a[i].ma=3,a[i].mid=2;
		}
		if(tepan1())return 0;
		if(tepan2())return 0;
		memset(b,false,sizeof(b));
		for(int i=n/2;i<=n;i++)b[i]=1;
		while(!b[0]){
			int s[4]={0};
			int j=n;
			while(b[j]==1)j--;
			for(int i=j;i<=n;i++)b[i]=!b[i];
			for(int i=1;i<=n;i++)
			if(b[i]&&s[a[i].ma]*2<n){
				s[a[i].ma]++;
				s[0]+=a[i].x[a[i].ma];
			}
			else s[0]+=a[i].x[a[i].mid];
			ma=max(ma,s[0]);
		}
		cout<<ma<<endl;
	}
	return 0;
}
/*
2 3 0
2 4 0
5 1 0
1 3 0
*/
