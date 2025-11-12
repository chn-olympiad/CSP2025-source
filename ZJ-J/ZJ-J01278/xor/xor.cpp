#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int a[N],n,k,pre[N],checka=1,checkb=1,tim,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	if(k!=0)checka=0;
	if(k!=0&&k!=1)checkb=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)checka=0;
		if(a[i]>1)checkb=0;
	}
	if(k==0&&(checka||checkb)){
		if(checka){
			cout<<(n/2)<<'\n';
			return 0;
		}
		for(int i=1;i<=n;){
			if(a[i]==0){
				ans++,i++;
				continue;
			}
			int lef=i,rig=i+1;
			while(a[rig]==0&&rig<=n)rig++;
			if(rig==n+1){
				i++;
				continue;
			}
			if(rig-lef>2)
				ans+=rig-lef-1,i=rig;
			else ans++,i=rig+1;
		}
		cout<<ans<<'\n';
		return 0;
	}
	for(int mask=1;(k>>(mask-1))>0;mask++){
		tim++;
		if((k>>(mask-1))&1==1){
			int flag=0;
			for(int i=1;i<=n;i++){
				if((a[i]>>(mask-1))&1==1){
					flag=1;
					break;
				}
			}
			if(flag)pre[1]++,pre[n+1]--;
			else {
				cout<<0<<'\n';
				return 0;
			}
			continue;
		}
		for(int i=1;i<=n;){
			if((a[i]>>(mask-1))&1==0){
				pre[i]++,pre[i+1]--;
				continue;
			}
			int lef=i,rig=i+1;
			while((a[rig]>>(mask-1))&1==0&&rig<=n)rig++;
			if(rig!=n+1){
				pre[lef]++,pre[rig+1]--;
				i=rig+1;
			}
			else i++;
		}
	}
	for(int i=1;i<=n;i++)
		pre[i]+=pre[i-1];
	int temp=0;
	for(int i=1;i<=n;i++){
		if(pre[i]==tim)temp^=a[i];
		if(temp==k&&pre[i]==tim){
			ans++,temp=0;
			continue;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
/*
4 2
2 1 0 3
2

4 3
2 1 0 3
2

4 0
2 1 0 3
1
*/
/*
5 0
1 1 1 1 1
2

6 0
1 1 1 1 1 1
3

5 1
1 0 1 1 1
4

5 0
1 0 1 1 1
2

10 0
1 0 0 1 1 0 1 1 1 1 
6

10 1
0 0 0 0 0 0 0 0 0 0 
*/