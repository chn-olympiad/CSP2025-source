#include<bits/stdc++.h>
using namespace std;
#define int long long
const int P=131;
unsigned int hs[500010];
int n,k,a[500010],mx,sm[500010],cnt_0,ans,tr[2000010];
map<pair<int,int>,int> mp;
int lw(int x){
	return x&(-x);
}
void upd(int x,int v){
	if (x==0){
		cnt_0+=1;
		return ;
	}
	while (x<=n){
		//cout<<x<<" "<<lw(x)<<endl;
		tr[x]+=v;
		x+=lw(x);
	}
}
int qr(int x){
	if (x<0)return 0;
	int res=0;
	while (x>0){
		//cout<<x<<" "<<lw(x)<<endl;
		res+=tr[x];
		x-=lw(x);
	}
	//cout<<cnt_0<<endl;
	return res+cnt_0;
}
void dfs(int l,int r){
	if (r==n+1){
		return ;
	}
	if (mp[{l,r}]==1 || qr(r)-qr(l-1)!=0){
		return ;
	}
	mp[{l,r}]=1;
	//cout<<l<<" "<<r<<" "<<(sm[r]^sm[l-1])<<" "<<k<<endl;
	if ((sm[r]^sm[l-1])==k){
		//cout<<"A"<<endl;
		ans+=1;
		upd(l,1);
		dfs(r+1,r+1);
	}else{
		//cout<<"B"<<endl;
		if (l+1<=r){
			dfs(l+1,r);
		}
		dfs(l,r+1);
	}
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f=0;
	for (int i=1;i<=n;++i){
		cin>>a[i];
		sm[i]=sm[i-1];
		sm[i]^=a[i];
		if (a[i]!=1){
			f=1;
		}
		mx=max(mx,a[i]);
	}
	if (log2(mx)<log2(k)){
		cout<<0<<endl;
		return 0;
	}
	if (!f){
		if (k==0){
			cout<<n/2<<endl;
		}else if (k==1){
			cout<<n<<endl;
		}else{
			cout<<0<<endl;
		}
		return 0;
	}
	f=0;
	for (int i=1;i<=n;++i){
		if (a[i]>1){
			f=1;
			break;
		}
	}	
	if (!f){
		if (k==0){
			for (int i=1;i<=n;++i){
				if (a[i]==0){
					ans+=1;
				}else if ((a[i-1]==1 && a[i]==1)){
					ans+=1;
					a[i]=a[i-1]=-1;
				}
			}
			cout<<ans<<endl;
		}else{
			for (int i=1;i<=n;++i){
				if (a[i]==1){
					ans+=1;
				}
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	dfs(1,1);
	cout<<ans<<endl;
	return 0;
}
/*
2 2
2 99 100 97 98
*/
