#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],cnt;
int mod(int cnt){
	return cnt%998%244%353;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<n-1;i++){
		for(int j=i+2;j<=n;j++){
			int max_num=0,tmp=0;
			for(int k=i;k<=j;k++){
				max_num=max(max_num,a[k]);
				tmp+=a[k];
			}
			if(tmp>max_num*2){
				cnt=mod(cnt+1);
			}
		}
	}
	cout<<mod(cnt);
	//我尽力了，但写出来的代码太糟糕了，放那半天运行不动，距离考试结束还有不到30分钟，我只能用旧的了，尽管我知道这个也很糟糕，我大概只能拿220分 
    return 0;
}
