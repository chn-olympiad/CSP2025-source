#include<bits/stdc++.h>
using namespace std;
struct amem{
	int i;
	int cl;
	int v;
	int dir;
	bool operator<(amem b){
		return v>b.v;
	}
} mems[300005];
int alset[100005];
int nums[15];
//如果改组一人 最小损失 
priority_queue<int> dirrem[15];
//int dp[100005][3];
bool isbetter(int v,int cl){
	return (-dirrem[cl].top())<v;
}
int vals[15]; 

void fun3(){
	memset(alset,0,sizeof alset);
	memset(nums,0,sizeof nums);
	for(int i=0;i<=4;i++) while(!dirrem[i].empty()) dirrem[i].pop();
	int n,limn;
	cin>>n;
//	cout<<n<<endl;
	limn=n/2;
	int tot=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>vals[j];
		}
//		cout<<"run"<<i<<" "<<vals[1]<<" "<<vals[2]<<" "<<vals[3]<<endl;
		for(int k=1;k<=3;k++){
			int dir=INT_MAX;
			for(int j=1;j<=3;j++){
				if(j!=k&&vals[k]>=vals[j]){
					dir=min(dir,vals[k]-vals[j]);
				}
			}
			mems[++tot]={i,k,vals[k],dir};
//			cout<<i<<" "<<k<<" "<<vals[k]<<" "<<dir<<endl;
		}
	}
	sort(mems+1,mems+1+tot);
	long long ans=0;
	for(int i=1;i<=tot;i++){
//			cout<<alset[mems[i].i]<<endl;
		if(!alset[mems[i].i]){
			alset[mems[i].i]=1;
			nums[mems[i].cl]++;
			ans+=mems[i].v;
			dirrem[mems[i].cl].push((-1)*mems[i].dir);
//				cout<<"ok"<<i<<" "<<mems[i].v<<mems[i].dir<<endl;
//				cout<<(-1)*mems[i].dir<<endl;
		}
	}
	for(int i=1;i<=3;i++){
		if(nums[i]>limn){
			for(int j=1;j<=nums[i]-limn;j++){
				ans+=dirrem[i].top();
				dirrem[i].pop();
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		fun3();
	}
	cout<<endl;
	return 0;
}
//void fun1(){
//	memset(alset,0,sizeof alset);
//	memset(nums,0,sizeof nums);
//	for(int i=0;i<=4;i++) while(!dirrem[i].empty()) dirrem[i].pop();
//	int n,limn;
//	cin>>n;
////	cout<<n<<endl;
//	limn=n/2;
//	int tot=0;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=3;j++){
//			cin>>vals[j];
//		}
////		cout<<"run"<<i<<" "<<vals[1]<<" "<<vals[2]<<" "<<vals[3]<<endl;
//		for(int k=1;k<=3;k++){
//			int dir=INT_MAX;
//			for(int j=1;j<=3;j++){
//				if(j!=k&&vals[k]>=vals[j]){
//					dir=min(dir,vals[k]-vals[j]);
//				}
//			}
//			mems[++tot]={i,k,vals[k],dir};
////			cout<<i<<" "<<k<<" "<<vals[k]<<" "<<dir<<endl;
//		}
//	}
//	sort(mems+1,mems+1+tot);
//	long long ans=0;
//	for(int i=1;i<=tot;i++){
////			cout<<alset[mems[i].i]<<endl;
//		if(!alset[mems[i].i]){
//			if(nums[mems[i].cl]<limn){
//				alset[mems[i].i]=1;
//				nums[mems[i].cl]++;
//				ans+=mems[i].v;
//				dirrem[mems[i].cl].push((-1)*mems[i].dir);
////				cout<<"ok"<<i<<" "<<mems[i].v<<mems[i].dir<<endl;
////				cout<<(-1)*mems[i].dir<<endl;
//			}
////				cout<<i<<" "<<mems[i].i<<" "<<mems[i].v<<endl;
//			else if(isbetter(mems[i].v,mems[i].cl)){
//				int cl=mems[i].cl;
////				cout<<"ok"<<i<<" "<<dirrem[cl].top()<<mems[i].v<<mems[i].dir<<endl;
//				ans+=(dirrem[cl].top())+mems[i].v;
//				dirrem[cl].pop();
//				dirrem[cl].push(mems[i].dir);
//				alset[mems[i].i]=1;
//			}
//		}
//	}
//	cout<<ans<<endl;
//}
//void fun2(){
//	memset(alset,0,sizeof alset);
//	memset(nums,0,sizeof nums);
//	int n,limn;
//	cin>>n;
//	limn=n/2;
//	int tot=0;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=3;j++){
//			int val;
//			cin>>val;
//			mems[++tot]={i,j,val};
//		}
//	}
//	sort(mems+1,mems+1+tot);
//	long long ans=0;
//	for(int i=1;i<=tot;i++){
////			cout<<alset[mems[i].i]<<endl;
//		if(!alset[mems[i].i]){
//			if(nums[mems[i].cl]<limn){
//				alset[mems[i].i]=1;
//				nums[mems[i].cl]++;
//				ans+=mems[i].v;
//			}
////				cout<<i<<" "<<mems[i].i<<" "<<mems[i].v<<endl;
//		}
//	}
//	cout<<ans<<endl;
//}
