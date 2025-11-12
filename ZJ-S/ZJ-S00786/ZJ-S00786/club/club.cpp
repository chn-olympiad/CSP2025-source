#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int,int> PII;
int n;
int a[100010][3],p[100010][3],s[100010],c[3];
priority_queue<PII> pq;
void solve()
{
	int i,ans=0;cin>>n;
	c[0]=c[1]=c[2]=0;
	while(pq.size())pq.pop();
	for(i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		p[i][0]=0,p[i][1]=1,p[i][2]=2;
		sort(p[i],p[i]+3,[&](int x,int y){
			return a[i][x]>a[i][y];
		});ans+=a[i][p[i][0]],c[p[i][s[i]=0]]++;
        pq.push((PII){a[i][p[i][s[i]+1]]-a[i][p[i][s[i]]],i}),s[i]++;
	}while(pq.size()&&max({c[0],c[1],c[2]})>n/2){
        int i=pq.top().y,sum=pq.top().x;pq.pop();
		if(c[p[i][s[i]-1]]>n/2){
			ans+=sum,c[p[i][s[i]-1]]--,c[p[i][s[i]]]++;
			pq.push((PII){a[i][p[i][s[i]+1]]-a[i][p[i][s[i]]],i}),s[i]++;
		}
    }cout<<ans<<'\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int _;cin>>_;
	while(_--)solve();
}
