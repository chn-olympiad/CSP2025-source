#include<bits/stdc++.h>
using namespace std;
int c,k;
int a[500010];
bool vis[100010];
void solve1(){
	int cnt=0;
	for(int l=1;l<=c;l++){
		int s=0,p=0;
		for(int i=1;i<=l;i++)
			s^=a[i],p+=vis[i];
		for(int i=1;i<=c-l+1;i++){
			if(s==k&&p==0){
				p=l;
				for(int j=i;j<=i+l-1;j++)
					vis[j]=1;
				cnt++;
			}
			s^=a[i];s^=a[i+l];
			p-=vis[i];p+=vis[i+l];
		}
	}
	cout<<cnt;
}
void solve2(){
	int cnt=0;
	for(int i=1;i<=c;i++)
		cnt+=a[i];
	if(k)cout<<cnt;
	else cout<<cnt/2;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>k;
	for(int i=1;i<=c;i++)
		cin>>a[i];
	if(c<=1000)solve1();
	else solve2();
	return 0;
}
