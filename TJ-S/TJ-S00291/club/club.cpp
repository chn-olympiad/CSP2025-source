#include<bits/stdc++.h>
#define int long long 
using namespace std;
int t;
int n;
struct Node{
	int x,y,z,maxx,cha,ty;
}a[200055];
int ct[4];
Node b[200055];
bool cmp(Node a,Node b){
	return a.cha<b.cha;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0),ios_base::sync_with_stdio(false);
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				a[i].maxx=a[i].x;
				a[i].cha=a[i].x-max(a[i].y,a[i].z);
				a[i].ty=1;
			}else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
				a[i].maxx=a[i].y;
				a[i].cha=a[i].y-max(a[i].x,a[i].z);
				a[i].ty=2;
			}else{
				a[i].maxx=a[i].z;
				a[i].cha=a[i].z-max(a[i].y,a[i].x);
				a[i].ty=3;
			}
			ct[a[i].ty]++;
			ans+=a[i].maxx;
		//	cout<<"#"<<a[i].ty<<" "<<a[i].maxx<<"\n";
		}
		int k=0;
		for(int i=1;i<=3;i++){
			if(ct[i]>(n/2)){
			//	cout<<ct[i]<<"^\n";
				k=i;
				break;
			}
		}
	//	cout<<"&"<<k<<"\n"; 
		if(k==0){
			cout<<ans<<"\n";
		}else{
			int cnt=0;
			for(int i=1;i<=n;i++){
			//	cout<<"@"<<a[i].ty<<" "<<k<<"\n"; 
				if(a[i].ty==k){
			///		cout<<"$";
					b[++cnt]=a[i];
				//	cout<<b[cnt].cha<<"*\n";
				}
			}
			sort(b+1,b+1+cnt,cmp);
			for(int i=1;i<=(ct[k]-(n/2));i++){
				ans-=b[i].cha;
			} 
			cout<<ans<<"\n";
		}
		for(int i=1;i<=n;i++){
			a[i]=b[i]=(Node){0,0,0,0,1000000,0};
		}
		ct[1]=ct[2]=ct[3]=0;
	}
	return 0; 	
}

