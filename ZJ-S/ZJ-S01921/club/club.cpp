#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define INF 2100000000
ll t,n,p,ans;
struct node{
	int x,y,z,mx,k,secmx;
}a[100005];
ll tot,s[5];
struct node2{
	int x,y;
}q[100005];
int k[100005];
bool cmp(node i,node j){
	return i.mx>j.mx;
}bool cmp2(node2 i,node2 j){
	return i.x<j.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;ans=0;
		for(int i=1;i<=3;i++) s[i]=0;
		for(int i=1;i<=n;i++)
			cin>>a[i].x>>a[i].y>>a[i].z,tot+=a[i].x+a[i].y+a[i].z;
		for(int i=1;i<=n;i++){
			k[i]=max(a[i].x,max(a[i].y,a[i].z));
			tot-=(a[i].x+a[i].y+a[i].z-k[i]);
			if(a[i].x==k[i]) s[1]++;
			else if(a[i].y==k[i]) s[2]++;
			else s[3]++;
		}
//		for(int i=1;i<=n;i++) cout<<k[i]<<' ';
//		cout<<endl;
//		for(int i=1;i<=3;i++) cout<<s[i]<<' ';
//		cout<<endl;
//		cout<<tot<<endl;
		for(int i=1;i<=3;i++){
			if(s[i]>n/2){
				for(int j=1;j<=n;j++){
					if(k[j]==a[j].x&&i==1){
						if(a[j].y>a[j].z)
							q[j].x=k[j]-a[j].y,q[j].y=2;
						else
							q[j].x=k[j]-a[j].z,q[j].y=3;
					}else if(k[j]==a[j].y&&i==2){
						if(a[j].x>a[j].z)
							q[j].x=k[j]-a[j].x,q[j].y=1;
						else
							q[j].x=k[j]-a[j].z,q[j].y=3;
					}else if(k[j]==a[j].z&&i==3){
						if(a[j].y>a[j].x)
							q[j].x=k[j]-a[j].y,q[j].y=2;
						else
							q[j].x=k[j]-a[j].x,q[j].y=1;
					}else{
						q[j].x=INF;
					}
				}
//				for(int j=1;j<=n;j++) cout<<q[j].x<<' ';
//				cout<<endl;
				sort(q+1,q+n+1,cmp2);
//				for(int j=1;j<=n;j++) cout<<q[j].x<<' ';
//				cout<<endl;
				for(int j=1;j<=s[i]-n/2;j++) tot-=q[j].x;
				break;
			}
		}
		cout<<tot<<endl;
		tot=0;
	}
}/*
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
