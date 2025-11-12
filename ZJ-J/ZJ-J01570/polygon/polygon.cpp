#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+5;
int n;
int a[maxn];
int lw=63;
int ans;
map<string,int> m;
bool cmp(char a,char b){
	return (int)a>(int)b;
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int s=1;s<(1<<min(n,lw));s++){
		int cnt=0,sum=0,maxa=0;
		char k[maxn];
		string t="";
		memset(k,0,sizeof(k));
		for(int i=1;i<=n;i++){
			if(s&(1<<(i-1))){
				k[++cnt]=char(i+'0');
				sum=sum+a[i];
				maxa=max(maxa,a[i]);
			}
		}
		sort(k+1,k+cnt+1,cmp);
		for(int i=1;i<=cnt;i++){
			t=t+k[i];
		}
		if(2*maxa<sum&&!m.count(t)&&cnt>=3){
			//cout<<"maxa:"<<maxa<<"sum:"<<sum<<"t:"<<t<<endl;
			ans++;
			m[t]=1;
		}
	}
	printf("%lld\n",ans%998%244%353);
	
	return 0;
}
