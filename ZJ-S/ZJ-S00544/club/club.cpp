#include<bits/stdc++.h>
using namespace std;
int T,n;
const int N=1e5;
struct node1{
	int x,y,z;
	int val,now,mn;
}a[N+10];
node1 b[N+10];
int head=0,tail=0;
int mn(int x,int y,int z){
	if(x<=y&&x<=z) return 1;
	else if(y<=x&&y<=z) return 2;
	else return 3;
}
int man(int x,int y,int z){
	if(x>=y&&x>=z) return 1;
	else if(y>=x&&y>=z) return 2;
	else return 3;
}
int man2(int x,int y,int z,int ma){
	if(ma==1){
		if(y>z) return 2;
		else return 3;
	}else if(ma==2){
		if(x>z) return 1;
		else return 3;
	}else{
		if(y>x) return 2;
		else return 1;	
	}
}
bool cmp(node1 a,node1 b){
	return a.val<b.val;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T){
		T--;
		cin>>n;
		head=0,tail=0;
		long long int ans=0;
		for(int i=1;i<=n;++i){
			int x,y,z;
			cin>>x>>y>>z;
			a[i].x=x,a[i].y=y,a[i].z=z;
			int tmp=mn(x,y,z);
			if(tmp==1)
				a[i].val=abs(y-z);
			else if(tmp==2)
				a[i].val=abs(z-x);
			else
				a[i].val=abs(x-y);
			tmp=man(x,y,z);
			a[i].now=man2(x,y,z,tmp);
			a[i].mn=tmp;
		}
		sort(a+1,a+1+n,cmp);
		int x=0,y=0,z=0;
		for(int i=1;i<=n;++i){	
			int tmp=man(a[i].x,a[i].y,a[i].z),k;
			if(a[i].now==1) k=a[i].x;
			if(a[i].now==2) k=a[i].y;
			if(a[i].now==3) k=a[i].z;
			if(tmp==1){
				if(x<n/2){
					x++;
					b[tail]=a[i];
					tail++;
					ans+=a[i].x;
				}else{
					while(b[head].mn!=tmp){
						head++;
					}
					if(a[i].val>b[head].val){
						ans-=b[head].val;
						ans+=a[i].x;					
						head++;
					}else{
						ans+=k;
					}
				}
			}
			if(tmp==2){
				if(y<n/2){
					y++;
					b[tail]=a[i];
					tail++;
					ans+=a[i].y;
				}else{
					while(b[head].mn!=tmp){
						head++;
					}
					if(a[i].val>b[head].val){
						ans-=b[head].val;
						ans+=a[i].y;					
						head++;
					}else{
						ans+=k;
					}
				}
			}
			if(tmp==3){
				if(z<n/2){
					z++;
					b[tail]=a[i];
					tail++;
					ans+=a[i].z;
				}else{
					while(b[head].mn!=tmp){
						head++;
					}					
					if(a[i].val>b[head].val){
						ans-=b[head].val;
						ans+=a[i].z;						
						head++;
					}else{
						ans+=k;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}/*3
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
4 0 0*/
/*
1
6
8 3 4
7 5 8
10 9 6
17 13 9
9 7 8
9 3 1
*/


