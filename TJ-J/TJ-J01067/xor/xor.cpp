#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e5+100;
int n,K,a[MAXN],b[MAXN],ans,l[MAXN],r[MAXN],flag;
bool A=1,B=1;

bool f(int L,int R){
	int cnt=0;
	for(int i=L;i<=R;i++) cnt^=a[i];
	return (cnt==K);
}

void dfs(int x,int i){ // 枚举所有区间 
	if(flag) return;
	if(i>x){
		flag=1;
	}
	for(int j=r[i-1]+1;j<=n-x+i;j++){
		for(int k=j;k<=n-x+i;k++){
			if(f(j,k)){
				l[i]=j, r[i]=k;
				dfs(x,i+1); 
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> K;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]>1) B=0;
	}
	if(B){ // 包含A,30pts 
		if(K==0){
			for(int i=1;i<=n;i++){
				if(!a[i]) ans++;
				else if(a[i-1] && !(b[i-1])) b[i-1]=b[i]=1, ans+=2;
			}
		}
		if(K==1){
			for(int i=1;i<=n;i++){
				if(a[i]) ans++;
			}
		}
		cout << ans;
		return 0;
	}
	
	
	int L=0,R=n,mid;
	while(L<R){
		mid=(L+R+1)>>1;
		flag=0;
		dfs(mid,1);
		if(flag) L=mid;
		else R=mid-1;
	}
	cout << L;
	
	return 0;
} 
