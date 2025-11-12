#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int maxn = 2e5;
int T,n,a[maxn][5],res;
int mmax(int a1,int a2,int a3){
	int res=1,maxx=a1;
	if(a2>maxx) maxx=a2,res=2;
	if(a3>maxx) maxx=a3,res=3;
	return res;
}
int mmin(int id){
	int res=1,minn=a[id][1];
	if(a[id][2]<minn) minn=a[id][2],res=2;
	if(a[id][3]<minn) minn=a[id][3],res=3;
	return res;
}
int getsecond(int id){
	if((a[id][1]>a[id][2]&&a[id][1]<a[id][3])||(a[id][1]<a[id][2]&&a[id][1]>a[id][3])) return 1;
	if((a[id][2]>a[id][1]&&a[id][2]<a[id][3])||(a[id][2]<a[id][1]&&a[id][2]>a[id][3])) return 2;
	if((a[id][3]>a[id][1]&&a[id][3]<a[id][2])||(a[id][3]<a[id][1]&&a[id][3]>a[id][2])) return 3;
	return 1;
}
struct Node{
	int person,max,wlist[5];
	bool friend operator < (Node aa,Node b){
		return a[aa.person][aa.max]>a[b.person][b.max];
	}
	Node(int a,int c):person(a),max(c),wlist({0,c,getsecond(a),mmin(a),0}){}
};
vector<Node> A;
int tot[5];
void sol1(){
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		A.push_back(Node(i,mmax(a[i][1],a[i][2],a[i][3])));
	}
	sort(A.begin(),A.end());
	for(int i=1;i<=n;i++){
		// try to select
		//cout<<"flk "<<A[i-1].person<<A[i-1].wlist[1]<<endl;
		for(int j=1;j<=3;j++){
			if(tot[A[i-1].wlist[j]]<n/2){
				tot[A[i-1].wlist[j]]++;
				res+=a[A[i-1].person][A[i-1].wlist[j]];
				//cout<<" select "<<i<<" to "<<A[i-1].max<<endl;
				break;
			} else {
				//todo lowerbound
			}
		}
	}
	cout<<res<<endl;
}
void dfs(int i,int ans){
	if(i==n+1){
		res=max(ans,res);
		return;
	}
	for(int j=1;j<=3;j++){
		if(tot[A[i-1].wlist[j]]<n/2){
			tot[A[i-1].wlist[j]]++;
			ans+=a[i][A[i-1].wlist[j]];
			dfs(i+1,ans);
			ans-=a[i][A[i-1].wlist[j]];
			tot[A[i-1].wlist[j]]--;
			//cout<<" select "<<i<<" to "<<A[i-1].max<<endl;
		}
	}
	return;
}
void sol2(){
	res=0;A.clear();
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		A.push_back(Node(i,mmax(a[i][1],a[i][2],a[i][3])));
	}
	dfs(1,0);
	cout<<res<<endl;
}
int main(){
	// if 大师。 
	// DP? 毁了忘了背包 
	// A tan B 
	//D场又没配虚拟机 没加挡板 i512400 商科512
	//我常常追忆过去。
	//Ren5Jie4Di4Ling5%
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		res=0;
		memset(tot,0,sizeof(tot));
		memset(a,0,sizeof(a));
		A.clear();
		if(n<=10){
			sol2();
		} else sol1();
	}
	return 0;
}
