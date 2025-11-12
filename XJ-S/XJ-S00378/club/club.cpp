#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
struct node{
	int x,y,z,t;
}a[N];
int n;
ll ans;
//struct Spb1{
//	int spb_r,spb_id;
//}spb1[N];
//struct Spb2{
//	int spb_rr,spb_id;
//}spb2[N];
bool cmp1(node a,node b){
	return a.x>b.x;
}
bool cmp2(node a,node b){
	return a.y>b.y;
}
bool cmp3(node a,node b){
	return a.z>b.z;
}
//bool cmp4(Spb1 a,Spb1 b){
//	return a.spb_r>b.spb_r;
//}
//bool cmp5(Spb2 a,Spb2 b){
//	return a.spb_rr>b.spb_rr;
//}
//bool cmp6(int g,int f){
//	return g>f;
//}
//int G[N];
int book[N];
void bfs(int step){
	if(step==n+1){
		int res=0;
		int l[4]={0,0,0,0};
		for(int i=1;i<=n;i++){
			//cout<<book[i]<<' ';
			l[book[i]]++;
			if(book[i]==1){
				res+=a[i].x;
			}else if(book[i]==2){
				res+=a[i].y;
			}else{
				res+=a[i].z;
			}
		}
		//cout<<res<<endl;
		if(l[1]>n/2 || l[2]>n/2 || l[3]>n/2){
			return;
		}
		if(res>ans){
			ans=res;
		}
		return;
	}
	for(int i=1;i<=3;i++){
		book[step]=i;
		bfs(step+1);
		book[step]=0;
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	bool sol1=true;
	int face=0;
	while(T--){
		ans=0;
		int mx=0,my=0,mz=0;
		int lx=0,ly=0,lz=0;
		cin>>n;
		int mi=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].x;
			cin>>a[i].y;
			cin>>a[i].z;
			a[i].t=max(max(a[i].x,a[i].y),a[i].z);
			if(a[i].t==a[i].x){
				mx++;
			}else if(a[i].t==a[i].y){
				my++;
			}else{
				mz++;
			}
			if(a[i].x!=0){
				lx++;
			}
			if(a[i].y!=0){
				ly++;
			}
			if(a[i].z!=0){
				lz++;
			}
		}
		if(my<=mi && mx<=mi && mz<=mi){  //Special C
			face=3;
			for(int i=1;i<=n;i++){
				ans+=a[i].t;
			}
			cout<<ans<<endl;
			//CCF真的太贪吃了，C才给10分 
		}else if((lx==0 && ly==0) || (lz==0 && ly==0) || (lx==0 && lz==0)){  //Special A
			face=2;
			if(lz==0 && ly==0){  //a1
				sort(a+1,a+1+n,cmp1);
				for(int i=1;i<=n/2;i++){
					ans+=a[i].x;
				}
			}else if(lx==0 && lz==0){  //a2
				sort(a+1,a+1+n,cmp2);
				for(int i=1;i<=n/2;i++){
					ans+=a[i].y;
				}
			}else if(lx==0 && ly==0){  //a3
				sort(a+1,a+1+n,cmp2);
				for(int i=1;i<=n/2;i++){
					ans+=a[i].z;
				}
			}
			cout<<ans<<endl;
		}/*else if(lz==0 && (ly!=0 && lx!=0)){  //Special B
			int cot1=0,cot2=0;
			for(int i=1;i<=n;i++){
				if(a[i].t==a[i].x){
					cot1++;
					spb1[cot1++].spb_r=a[i].t;
					spb1[cot1++].spb_id=i;
				}else if(a[i].t==a[i].y){
					cot2++;
					spb2[cot2++].spb_rr=a[i].t;
					spb2[cot2++].spb_id=i;
				}
			}
			sort(spb1+1,spb1+1+cot1,cmp4);
			sort(spb2+1,spb2+1+cot2,cmp5);
			int dx=cot1-cot2;
			int mi=n/2;
			if(dx=!0){
				if(cot1-cot2>0){
					int dc=cot1-cot2;
					if(dc%2==0){
						int dcc=dc/2;
						for(int i=cot2+1;i<=cot2+dcc;i++){
							spb2[i].spb_rr=a[i].y;
						}
						sort(spb2+1,spb2+1+cot2,cmp5);
						for(int i=1;i<=mi/2;i++){
							ans+=spb1[i].spb_r+spb2[i].spb_rr;
						}
					}else{
//						int dcc=floor((dc*1.0)/2.0);
//						for(int i=cot2+1;i<=cot2+dcc;i++){
//							spb2[i].spb_r=a[i].y;
//							spb2[i].spb_id=spb1[i].spb_id;
//						}
//						//sort(spb1+1,spb1+1+cot1,cmp4);
//						sort(spb2+1,spb2+1+cot2,cmp5);
//						if(a[spb1[i].spb_id].x>a[spb2[i].spb_id].x){
//							spb2[i].spb_r=a[spb1[i].spb_id].x； 
//						}
						for(int i=cot2+1;i<=cot2+dc;i++){
							G[i-cot2]=a[spb1[i].spb_id].y;
						}
						sort(G+1,G+1+dc,cmp6);
						for(int i=1;i<=cot1;i++){
							ans+=spb1[i].spb_r;
						}
						for(int i=1;i<=cot2;i++){
							ans+=spb2[i].spb_rr;
						}
						for(int i=1;i<=dc-1;i++){
							ans+=G[i];
						}
					}
				}else{
					int dc=cot1-cot2;
					dc*=-1;
					if(dc%2==0){
						int dcc=dc/2;
						for(int i=cot1+1;i<=cot1+dcc;i++){
							spb1[i].spb_r=a[i].x;
						}
						sort(spb1+1,spb1+1+cot1,cmp4);
						for(int i=1;i<=mi/2;i++){
							ans+=spb1[i].spb_r+spb2[i].spb_rr;
						}
					}else{
						for(int i=cot1+1;i<=cot1+dc;i++){
							G[i-cot1]=a[spb2[i].spb_id].y;
						}
						sort(G+1,G+1+dc,cmp6);
						for(int i=1;i<=cot2;i++){
							ans+=spb2[i].spb_rr;
						}
						for(int i=1;i<=cot1;i++){
							ans+=spb1[i].spb_r;
						}
						for(int i=1;i<=dc-1;i++){
							ans+=G[i];
						}
					}
				}
			}
			for(int i=1;i<=n;i++){
				ans+=a[i].t;
			}
			cout<<ans<<endl;
			continue;
		}*/else{
			face=1;
			bfs(1);
			cout<<ans<<endl;
		}
		//cout<<face<<endl;
	}
	return 0;
}
