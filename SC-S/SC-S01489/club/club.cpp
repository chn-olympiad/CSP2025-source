#include<bits/stdc++.h>
using namespace std;
/*
题意：
有n个三元组，选第i个的次数不能超过n/2
求最大和
思路：
以最大的方案分配
（加三元组中最大的）
O(n)
对每个非法集合进行调整
(从最小的开始移，移到最大收益处)
O(nlogn)
*/
int n,a[100001][4],ans;//x的和，y的和，z的和
vector<int> x,y,z;//所选数的编号
int dx[100001],dy[100001],dz[100001];//修改代价
void ipu(){//输入
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int ma=max({a[i][1],a[i][2],a[i][3]});
		dx[i]=a[i][1]-max(a[i][2],a[i][3]);
		dy[i]=a[i][2]-max(a[i][1],a[i][3]);
		dz[i]=a[i][3]-max(a[i][1],a[i][2]);
		if(ma==a[i][1]){
			ans+=a[i][1];
			x.push_back(i);
		}
		else if(ma==a[i][2]){ 
			ans+=a[i][2];
			y.push_back(i);
		}
		else if(ma==a[i][3]){
			ans+=a[i][3];
			z.push_back(i);
		}
	}
	return ;
}
bool cmpx(int t1,int t2){return dx[t1]<dx[t2];}//排满意度
bool cmpy(int t1,int t2){return dy[t1]<dy[t2];}
bool cmpz(int t1,int t2){return dz[t1]<dz[t2];}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		ans=0;
		x.clear();
		y.clear();
		z.clear();
		ipu();
//		for(int X:x) cout<<X<<" ";
//		cout<<"\n";
//		for(int Y:y) cout<<Y<<" ";
//		cout<<"\n";
//		for(int Z:z) cout<<Z<<" ";
//		cout<<"\n";
		int lx=x.size(),ly=y.size(),lz=z.size();
		if(lx>n/2){
//			cout<<"YES1\n";
			sort(begin(x),end(x),cmpx);
//			for(int X:x) cout<<a[X][1]<<" ";
//			cout<<"\n";
			for(int i=0;i<lx-n/2;i++){
//				cout<<a[x[i]][1]<<"\n";
				ans-=a[x[i]][1];//消除
				if(a[x[i]][2]>=a[x[i]][3]) ans+=a[x[i]][2];
				else ans+=a[x[i]][3];
			}
		}
		else if(ly>n/2){
//			cout<<"YES2\n";
			sort(begin(y),end(y),cmpy);
//			for(int Y:y) cout<<a[Y][2]<<" ";
//			cout<<"\n";
			for(int i=0;i<ly-n/2;i++){
//				cout<<a[y[i]][2]<<"\n";
				ans-=a[y[i]][2];
				if(a[y[i]][1]>=a[y[i]][3]) ans+=a[y[i]][1];
				else ans+=a[y[i]][3];
			}
		}
		else if(lz>n/2){
//			cout<<"YES3\n";
			sort(begin(z),end(z),cmpz);
//			for(int Z:z) cout<<a[Z][3]<<"\n";
//			cout<<"\n";
			for(int i=0;i<lz-n/2;i++){
				ans-=a[z[i]][3];
				if(a[z[i]][1]>a[z[i]][2]) ans+=a[z[i]][1];
				else ans+=a[z[i]][2];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}