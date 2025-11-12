/*
2025 CCF CSP-S Task1 社团招新(club) 
*/ 
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e5+5;
struct node{
	ll club1,club2,club3;
}a[N];
ll n,box[N],ans=-1e9;
bool check(int n);
void solve_A();//特殊性质A专用函数 所有社团2与3满意度均为0 
bool cmp(node x,node y);//特殊性质A专用函数，详见114行
void solve_B();//特殊性质B专用函数 所有社团3满意度均为0
void dfs_B(int cur);//特殊性质B专用函数，不搜最后一位(i:1~2) 卡常
void dfs(int cur){
	//可行性剪枝，若当前已经有社团超过了限制，停止搜索
	int cnt1=0,cnt2=0,cnt3=0;
	for(int i=1;i<=cur;i++){
		if(box[i]==1){
			cnt1++;
		}else if(box[i]==2){
			cnt2++;
		}else{
			cnt3++;
		}
	} 
	if(cnt1>n/2 || cnt2>n/2 || cnt3>n/2){
//		cout<<"剪枝,人数"<<cnt1<<" "<<cnt2<<" "<<cnt3<<"满意度：";
		ll cnt=0;
			for(ll i=1;i<=n;i++){
				if(box[i]==1){
					cnt+=a[i].club1;
				}else if(box[i]==2){
					cnt+=a[i].club2;
				}else{
					cnt+=a[i].club3;
				}
			}
//		cout<<cnt;
//		if(cnt>147325){
//			cout<<"!!!";
//		}
//		cout<<"\n";
	}
//	else{
////		cout<<"没有剪枝"<<cnt1<<" "<<cnt2<<" "<<cnt3<<"\n";
//	}
	if(cur>n){
//		for(int i=1;i<=n;i++){
//			cout<<box[i]<<" ";
//		}
//		cout<<"\n"; 
		//筛选
		if(check(n)){ //可行 
			ll cnt=0;
			for(ll i=1;i<=n;i++){
				if(box[i]==1){
					cnt+=a[i].club1;
				}else if(box[i]==2){
					cnt+=a[i].club2;
				}else{
					cnt+=a[i].club3;
				}
			}
			//打擂台
//			if(ans<cnt){
////				cout<<"更新答案："<<ans<<"->"<<cnt<<"\n";
//			} 
			ans=max(ans,cnt);
//			cout<<"------"<<cnt<<"\n";
		}
		return ;
	}
	for(ll i=1;i<=3;i++){
		box[cur]=i;//3选n全排列 
		dfs(cur+1);
	}
}

void solve(){
	memset(a,0,sizeof(a)); //初始化数组 
	cin>>n;
	bool flag_A=0,flag_B=0; //初始化特殊性质标记 
	//输入 
	for(int i=1;i<=n;i++){
		cin>>a[i].club1>>a[i].club2>>a[i].club3;
		if(a[i].club2!=0 || a[i].club3!=0){
			flag_A=1; //非特殊性质A特征 
		}
		if(a[i].club3!=0){
			flag_B=1; //非特殊性质B特征 
		}
	}
	if(flag_A==0){ //当前数据是特殊性质A 
		solve_A();//调用特殊性质A专用函数 
		return ;
	}
	if(flag_B==0){ //当前数据是特殊性质B 
		solve_B(); //调用特殊性质B专用函数 
		return ;
	}
//	cout<<"-------";
	//搜索
	dfs(1);//调用通用函数(无特殊性质) 
	cout<<ans<<"\n";
}

int main(){
	freopen("club.in","r",stdin); //输入重定向 
	freopen("club.out","w",stdout); //输出重定向 
	//特殊性质A:对于所有1<=i<=n，均有a_i_2=a_i_3=0
	//特殊性质B:对于所有1<=i<=n，均有a_i_3=0 
	int t;
	cin>>t;
	while(t--){
		solve(); //通用函数(无特殊性质) 
		ans=-1e9; //最大值初始最小 
	} 
	return 0;
}

bool check(int n){ //检查分配方案是否合法 
	int cnt1=0,cnt2=0,cnt3=0;
	for(int i=1;i<=n;i++){
		if(box[i]==1){
			cnt1++;
		}else if(box[i]==2){
			cnt2++;
		}else{
			cnt3++;
		}
	} 
	if(cnt1<=n/2 && cnt2<=n/2 && cnt3<=n/2){
//		for(int i=1;i<=n;i++){
//			cout<<box[i]<<" ";
//		}
//		cout<<"\n"; 
		return 1;
	}
	return 0;
}

bool cmp(node x,node y){ //特殊性质A专用函数 
	return x.club1>y.club1;
}

void solve_A(){ //特殊性质A专用函数 
	//社团2与3均为0，排序(社团1满意度降序)，计算前n/2对于社团1的满意度和
	sort(a+1,a+1+n,cmp); 
//	for(int i=1;i<=n;i++){
//		cout<<a[i].club1<<a[i].club2<<a[i].club3<<"\n";
//	}
	int ans=0;
	for(int i=1;i<=n/2;i++){
		ans+=a[i].club1;
	}
	cout<<ans<<"\n";
} 

void dfs_B(int cur){ //特殊性质B专用搜索 
	if(cur>n){
		if(check(n)){
			//计算
			ll cnt=0;
			for(ll i=1;i<=n;i++){
				if(box[i]==1){
					cnt+=a[i].club1;
				}else if(box[i]==2){
					cnt+=a[i].club2;
				}else{
					cnt+=a[i].club3;
				}
			}
			//打擂台
			ans=max(ans,cnt); 
		}
		return ;
	}
	//卡常
	box[cur]=1;
	dfs(cur+1);
	box[cur]=2;
	dfs(cur+1);
} 

void solve_B(){ //特殊性质B专用函数 
	//搜索，最后一位不搜(i:1~2)
	dfs_B(1);
	cout<<ans<<"\n";
}


