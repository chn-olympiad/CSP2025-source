#include<bits/stdc++.h>

using namespace std;

#define int long long

int n,k;

const int N=5*1e5+5;

int a[N];

int c[N]; 

int dp[N];

vector<int> v;

int read(){
	int x=0;
	
	char c=getchar();
	
	while(c>='0'&&c<='9'){
		x*=10;
		x+=(c-'0');
		
		c=getchar();
	}
	
	return x;
}

signed main(){
//	freopen("xor7.in","r",stdin);	
//	freopen("ans.out","w",stdout);	
	freopen("xor.in","r",stdin);	
	freopen("xor.out","w",stdout);	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	n=read();
	k=read();
//	cout<<n<<" "<<k<<endl;
//	cin>>n>>k;
	
//	cout<<n<<endl;
	
	for(int i=1;i<=n;i++){
		a[i]=read();
//		cin>>a[i];
		c[i]=(a[i]^c[i-1]);
	}
	

	
	int mx=0,gc=0;
	
	v.push_back(0);
	int flag=0;	
	for(int i=1;i<=n;i++){
		if(gc){
			dp[i]+=(a[i]==k);
			dp[i]+=dp[i-1];
		}else{
			dp[i]=dp[i-1];
			
			for(auto j:v){
				flag=0;
				for(int l=j+1;l<=i;l++){
					if((c[j]^c[l])==k){
						dp[i]=(dp[j]+1>dp[i]?dp[j]+1:dp[i]);
						flag=1;
						break;
					}
				}
				if(flag) break;
			} 
		}
		if(dp[i]>mx){
			gc=1;
			mx=dp[i];
			v.clear();
			v.push_back(i);
		}else{
			gc=0;
			v.push_back(i);
		}
		
	}
	
	cout<<dp[n]<<'\n';
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
枚举l,r?
O(n2×n)=O(n3)
No
前缀和优化?
O(n2)
No 

以上算法都无法找到最大数 

由于[l,r]不可以重合

考虑DP

我们在意最大区间数，坐标是否被取过，等值

算了先打暴力dfs吧 

根据dfs

发现一共有两种状态 

定义DP[i]为前[1,i]区间中最大的区间数

转移

DP[i]=DP[j]+([j+1,i]是否存在合法区间)

O(n3)

显然不行，期望得分60pts 

考虑优化 

考虑时间O(n)或O(N log N)

9:56突然发现a[i]的范围很小，可以用桶存

11:00 发现可以优化DP
然后跑过了2e5

但5e5不知道 

wcwc

期望得分变成了80分 

自己造了组样例，发现跑不过 

wcwc 跑过了

加上ios 0.7S左右

希望卡常可以卡过 

加入了快读

快了0.03s左右 



in:
4 2
2 1 0 3
out:
2
in:
4 3
2 1 0 3
out:
2
in:
 
out:
1
*/
