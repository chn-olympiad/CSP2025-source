#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[500005],n,k,xor_prev[500005],ans,idx;
int dict[500005];
bool vis[500005];
struct xx{
	int start,end,len;	
}t[500005];
bool cmp(xx x,xx y){
	if(x.end==y.end)return x.len <y.len ;
	return x.end<y.end;
	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	memset(dict,0x3f3f3f3f,sizeof(dict));
	cin>>n>>k;
	cin>>a[1];
	xor_prev[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		xor_prev[i]=(a[i] ^ xor_prev[i-1]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((xor_prev[j] ^ xor_prev[i] ^ a[i])==k){
				t[++idx].start=i;
				t[idx].end=j;
				t[idx].len=j-i+1;
				break;
			}
		}
	}
	sort(t+1,t+1+idx,cmp);
	for(int i=1;i<=idx;i++){
		bool flag=0;
		for(int j=t[i].start;j<=t[i].end;j++){
			if(vis[j]){
				flag=1;
				break;
			}
		}
		if(flag)continue;
		for(int j=t[i].start;j<=t[i].end;j++){
			vis[j]=1;
		}
		ans++;
	}
	cout<<ans;
	return 0;
}