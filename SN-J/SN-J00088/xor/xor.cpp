#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e5+7;
int n, k;
#define show(x) cout<<(#x)<<" = "<<x<<"\n"
#define Show(x) cout<<(#x)<<" = "<<x<<" "
//至少有一个是最高位至少相同 
// k_i==0, sum_i%2==0; 
int a[N];
int kin2[27], numin2[N][27], maxw[N];
int sum[N][27]; //有几个二进制位为1
int ans=0; 
signed R[N];
struct node{
	int l, r;
};
vector<node> vec;
bool cmp(node a, node b){
	if(a.r!=b.r)return a.r<b.r;
	return a.l>b.l;
} 
signed main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
/*
*/
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	int k2=k, maxwk=0;
	for(int i=0;i<=22;i++)
		if(k>>i&1) maxwk=i;//最高位, 0-base 
	for(int i=0;i<=maxwk;i++){
		if(k>>i&1) kin2[i]=1;
	}
/*
	cerr<<"kin2is:  \n";//show k
	for(int i=21;i>=0;i--) cout<<kin2[i]; cout<<"\n";//
*/
	for(int i=1;i<=n;i++){
		for(int j=0;j<=22;j++)
			if(a[i]>>j&1) maxw[i]=j;
			
		for(int j=0;j<=maxw[i];j++)
			if(a[i]>>j&1) numin2[i][j]=1;
	}
/*
	for(int i=1;i<=n;i++){//show num
		for(int j=maxw[i];j>=0;j--){
			cout<<numin2[i][j];
		}cout<<" ";
	} cout<<"\n";//
*/
	for(int i=1;i<=n;i++){
		for(int j=0;j<=22;j++){
			sum[i][j]=sum[i-1][j]+numin2[i][j];
		}
	}
/*
	for(int i=1;i<=n;i++){//show sum
		for(int j=21;j>=0;j--){
			cout<<sum[i][j];
		}cout<<" ";
	}	//
*/
	for(int i=1;i<=n;i++){//这是瓶颈。如何优化？ 
		for(int j=i;j<=n;j++){
//			Show(i); show(j);
			bool OK=1;
			int wei[27];
			for(int k=0;k<=22;k++) wei[k]=sum[j][k]-sum[i-1][k];
			for(int k=0;k<=22;k++){
				if(kin2[k]) if(wei[k]%2==0) OK=0;
				if(!kin2[k]) if(wei[k]%2==1) OK=0;
				if(OK==0){
					break;
				}
			}
			if(OK){
//				cout<<"OK: "; Show(i); show(j);
				R[i]=j;//最左能满足和是k的 
				vec.push_back({i, j});
				break;
//				j--;
			}
		}
	}
	//接下来，区间贪心！
	sort(vec.begin(), vec.end(), cmp);
	int L=0, R=0;
	while(L<vec.size()){
		bool OK=1;
		if(L!=R) break;
//		Show(L); show(R);
		++ans; R=L;
		if(L==vec.size()) break;
		int r=vec[L].r;
		for(;R<vec.size();++R){
			if(vec[R].l>r){
				L=R;
				break;
			}
		}
		if(OK==0) break;
	}
	cout<<ans<<"\n";
}
//如果正确性，至少60pts; 
//正确性显然。但是n^2复杂度 
//  1<<20=1048576
// 5e5
/*
4 0
2 1 0 3
*/
//灌注luogu@GX6zm
//谢谢喵 
