#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int a[MAXN];
long long ans=0;
long long cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool f=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			f=false;
		}
	}
	if(f){
		cout<<n/2<<'\n';
		return 0;
	}else{
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int o=i;o<=j;o++){
					if(o==i) ans=a[i];
					else ans^=a[i];
				}
				if(ans==k) cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
//能不能给我一首歌的时间  
