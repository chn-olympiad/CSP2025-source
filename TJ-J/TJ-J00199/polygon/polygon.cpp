#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
const int N=5010;
const int mod=998244353;
int n,ans,sum,ma;
int a[N];
bool f[N];
map<int,int> cnt;

vector<int> rec;

void search(int t,int s,int k){
	if(t>k){
		ma=*max_element(rec.begin(),rec.end());
		if(sum<= 2*ma ){
			return;
		}
		ans=(ans+1)%mod;
		return;
	}for(int i=s;i<=n;i++){
		if(f[i]==0){
			sum+=a[i];
			rec.push_back(a[i]);
			ma=max(ma,a[i]);
			f[i]=1;
			search(t+1,i,k);
			
			sum-=*(rec.end()-1);
			rec.erase(rec.end()-1);
			ma=-1;
			f[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	
	ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}for(int i=3;i<=n;i++){
		ma=-1;
		sum=0;
		search(1,1,i);
	}
	printf("%d",ans);
	 
	return 0;
}
