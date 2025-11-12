#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int mx=INT_MIN,mn=INT_MAX;
long long tp_ans=0,tp_ans2=0;
long long orx_orx[500005];
struct ss{
	int a,b;
}h[500005];
bool cmp(ss x,ss y){
	if(x.b==y.b){
		return x.a>y.a;
	}else{
		return x.b<y.b;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		orx_orx[i]=orx_orx[i-1]^a[i];
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
		if(a[i]==1){
			tp_ans++;
		}
		if(a[i]==0){
			tp_ans2++;
		}
	}
//	if(k==0&&mx==1&&mn==1){
//		cout<<n/2;//1,3
//	}else if(k==1&&mx==1){//2,4,5,13
//		cout<<tp_ans;
//	}else if(k==mx&&k==mn){//pian ?
//		cout<<n;
//	}else if(k==0&&mn==0&&mx==1){//2,4,5,13
//		cout<<tp_ans/2+tp_ans2;
//	}else{
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if((orx_orx[j]^orx_orx[i-1])==k){
					ans++;
					h[ans].a=i;
					h[ans].b=j;
				}
			}
		}
		sort(h+1,h+1+ans,cmp);
		long long p=h[1].b,cnt=1;
		for(int i=2;i<=ans;i++){
			if(h[i].a>p){
				cnt++;
				p=h[i].b;
			}
		}
		cout<<cnt;
//	}
	return 0;
}

