//考号:SN-J00425 姓名:强小轩 学校:渭南初级中学 
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ldb long double
using namespace std;
typedef pair<int,int> Pii;
int n,k,a[500005],ans;
int sum[500005];//前缀异或和
int b[500005];//sum处理后
set<int> s;//待选序列 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		b[i]=sum[i]^k;
	}
	for(int i=1;i<=n;i++){
		//特判：从开头到i 
		if(sum[i]==k&&ans==0){
			s.clear();
			ans++;
		} 
		//否则，尝试配对 
		else{
			//若可以配对 
			if(s.find(b[i])!=s.end()){
				s.clear();
				ans++;
			}
		}
		s.insert(sum[i]);
	}
	cout<<ans<<'\n';
	return 0;
}







































