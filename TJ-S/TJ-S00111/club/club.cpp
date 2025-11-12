#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int a[MAXN];
long long ans=0;
int cnt=0;
bool cmp(int a, int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=3*n;i++){
			int x;
			cin>>x;
			if(i%3==1) a[++cnt]=x;
		}
		sort(a+1, a+1+cnt, cmp); 
		for(int i=0;i<=cnt/2;i++) ans+=a[i];
		cout<<ans<<'\n';
	}
	return 0;
}
//你说你有点难追 想让我知难而退 
//礼物不许挑最贵 只要香榭的落叶 
//营造浪漫的约会 不害怕搞砸一切 
//拥有你就拥有 全世界 
