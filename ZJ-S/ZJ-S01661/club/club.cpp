#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
struct node{
	long long w1,w2,w3;
}res[N];
long long a[N],b[N],c[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long T;
	cin>>T;
	while(T--){
		long long n,sum=0;
		long long cnt1=0,cnt2=0,cnt3=0;
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>res[i].w1>>res[i].w2>>res[i].w3;
			if(res[i].w1>res[i].w2&&res[i].w1>res[i].w3) a[++cnt1]=res[i].w1-max(res[i].w2,res[i].w3);
			if(res[i].w2>res[i].w1&&res[i].w2>res[i].w3) b[++cnt2]=res[i].w2-max(res[i].w1,res[i].w3);
			if(res[i].w3>res[i].w1&&res[i].w3>res[i].w2) c[++cnt3]=res[i].w3-max(res[i].w1,res[i].w2);
			sum+=max(res[i].w1,max(res[i].w2,res[i].w3));
		}
		if(cnt1>n/2){
			sort(a+1,a+cnt1+1);
			for(long long i=1;i<=cnt1-n/2;i++) sum-=a[i];
		}
		else if(cnt2>n/2){
			sort(b+1,b+cnt2+1);
			for(long long i=1;i<=cnt2-n/2;i++) sum-=b[i];
		}
		else if(cnt3>n/2){
			sort(c+1,c+cnt3+1);
			for(long long i=1;i<=cnt3-n/2;i++) sum-=c[i];
		}
		cout<<sum<<"\n";
	}
	return 0;
}
