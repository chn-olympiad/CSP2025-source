#include<bits/stdc++.h>
using namespace std;
const int slen=5e5+10;
int cnt[slen],n,k,ans;
bool v[slen];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int x;
	scanf("%d%d%d",&n,&k,&x);
	cnt[1]=x;
	for(int i=2;i<=n;i++){
		scanf("%d",&x);
		cnt[i]=cnt[i-1]^x;
	}
	for(int i=1;i<=n;i++){
		int temp=i-1;
		while(v[temp]!=1&&temp>=0){
			int s=cnt[i]^cnt[temp];
			if(s==k){
				v[i-1]=1;ans++;
				break;
			}
			temp--;
		}
	}
	printf("%d",ans);
	return 0;
}