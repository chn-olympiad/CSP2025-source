//#include<bits/stdc++.h>
//using namespace std;
//const int N=1e5+5;
//struct node{
//	int x,y,z,ax,ay,az;
//}a[N];
//void f(node &x){
//	int maxx=max(max(x.x,x.y),x.z);
//	if(x.x==maxx){
//		int maxn=max(x.y,x.z);
//		if(x.y==maxn){
//			//^_^
//		}else{
//			swap(x.y,x.z);
//			swap(x.ay,x.az);
//		}
//		return;
//	}else if(x.y==maxx){
//		swap(x.x,x.y);
//		swap(x.ax,x.ay);
//		int maxn=max(x.y,x.z);
//		if(x.y==maxn){
//			//^_^
//		}else{
//			swap(x.y,x.z);
//			swap(x.ay,x.az);
//		}
//		return;
//	}else if(x.z==maxx){
//		swap(x.x,x.z);
//		swap(x.ax,x.az);
//		int maxn=max(x.y,x.z);
//		if(x.y==maxn){
//			//^_^
//		}else{
//			swap(x.y,x.z);
//			swap(x.ay,x.az);
//		}
//		return;
//	}
//}
//bool cmp(node a,node b){
//	if(a.ax==b.ax){
//		return a.x>b.x;
//	}else if(a.ay==b.ay){
//		return a.y>b.y;
//	}
//	return 1;
//}
//int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	int t;
//	cin>>t;
//	while(t--){
//		long long ans=0;
//		int n;
//		int sum[5]={0,0,0,0,0};
//		cin>>n;
//		for(int i=1;i<=n;i++){
//			cin>>a[i].x>>a[i].y>>a[i].z;
//			a[i].ax=1;
//			a[i].ay=2;
//			a[i].az=3;
//			f(a[i]);
//		}
//		sort(a+1,a+n+1,cmp);
////		for(int i=1;i<=n;i++){
////			cout<<a[i].x<<" "<<a[i].ax<<" / "<<a[i].y<<" "<<a[i].ay<<" / "<<a[i].z<<" "<<a[i].az<<"\n";
////		}
////		cout<<"----------\n";
//		for(int i=1;i<=n;i++){
//			if(sum[a[i].ax]<(n/2)){
//				ans+=a[i].x;
//				sum[a[i].ax]++;
//			}else if(a[i].y>a[i].z){
//				ans+=a[i].y;
//				sum[a[i].ay]++;
//			}else if(sum[a[i].ay]<sum[a[i].az]){
//				ans+=a[i].y;
//				sum[a[i].ay]++;
//			}else if(sum[a[i].ay]>sum[a[i].az]){
//				ans+=a[i].z;
//				sum[a[i].az]++;
//			}
//		}
//		cout<<ans<<"\n";
//	}
//	return 0;
//}

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N][5],sum[5];
long long ans=0,maxx=-1;
void dfs(int x){
	if(x>n){
		return;
	}
	for(int i=1;i<=3;i++){
		if(sum[i]<(n/2)){
			ans+=(long long)a[x][i];
			sum[i]++;
			maxx=max(maxx,ans);
			dfs(x+1);
			ans-=(long long)a[x][i];
			sum[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		maxx=-1;
		ans=0;
		sum[1]=0;
		sum[2]=0;
		sum[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1);
		cout<<maxx<<"\n";
	}
	return 0;
}
