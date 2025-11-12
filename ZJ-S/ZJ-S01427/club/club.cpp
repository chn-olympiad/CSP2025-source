#include<bits/stdc++.h>
#define endl '\n'
//#define int long long
using namespace std;
int a[100010][5];
bool vis[100010];
vector<int> v1,v2,v3; 
struct node{
	int x,id;
};
bool cmp(node x,node y){
	return x.x<y.x;
}
vector<node> sub;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		v1.clear();
		v2.clear();
		v3.clear();
		sub.clear(); 
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			vis[i]=0;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int maxt=max(max(a[i][1],a[i][2]),a[i][3]);
			ans+=maxt;
			if(maxt==a[i][1]){
				v1.push_back(i);
			}else if(maxt==a[i][2]){
				v2.push_back(i);
			}else{
				v3.push_back(i);
			}
		}
//		for(int i=0;i<v2.size();i++){
//			cout<<v2[i]<<" ";
//		}
//		cout<<endl;
		int cnt=0;
		if(v1.size()>n/2){
			cnt=v1.size();
			for(int i=0;i<v1.size();i++){
				sub.push_back(node{a[v1[i]][1]-a[v1[i]][2],v1[i]});
				sub.push_back(node{a[v1[i]][1]-a[v1[i]][3],v1[i]});
			}
		}
		if(v2.size()>n/2){
			cnt=v2.size();
			for(int i=0;i<v2.size();i++){
				sub.push_back(node{a[v2[i]][2]-a[v2[i]][1],v2[i]});
				sub.push_back(node{a[v2[i]][2]-a[v2[i]][3],v2[i]});
//				cout<<a[i][2]-a[i][1]<<" "<<a[i][2]-a[i][3]<<endl;
			}
		}
		if(v3.size()>n/2){
			cnt=v3.size();
			for(int i=0;i<v3.size();i++){
				sub.push_back(node{a[v3[i]][3]-a[v3[i]][2],v3[i]});
				sub.push_back(node{a[v3[i]][3]-a[v3[i]][1],v3[i]});
			}
		}
//		cout<<cnt<<endl;
		sort(sub.begin(),sub.end(),cmp);
//		for(int i=0;i<sub.size();i++){
//			cout<<sub[i]<<" ";
//		}
//		cout<<endl;
		int k=0;
		for(int i=0;i<sub.size();i++){
			if(!vis[sub[i].id]){
				ans-=sub[i].x;
				vis[sub[i].id]=1;
				k++;
			}
			if(k==cnt-n/2){
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
//每一个先取最大值，然后进行调配
//我们发现最多只有一个组人数>n/2，这是显然的 
//思考如何调配
//我们查看哪(d-n/2)（d为组中人数）个人改为别的组时减少得最小
//保存所有的差，O(nlogn)排序即可 
//记得排序时标记是哪个人的差，防止一个人去两个组的情况 
//O(nlogn),期望得分 100 pts ^_^
//hyw
//AFO.
