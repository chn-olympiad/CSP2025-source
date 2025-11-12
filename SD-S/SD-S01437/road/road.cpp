#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;
int n,m,k;
long long ans;
const int N = 2*1e6;
const int M = 1e4+10;


bool st[M];
struct Node{
	int a,b;
	LL w;
}wu[N];
LL idx;
int p[M];



bool cmp(const Node & a,const Node &b)
{
	return a.w < b.w;
}

int find(int x)
{
	if(x!=p[x]) p[x] = find(p[x]);
	return p[x];
}





int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	
	for(int i = 1 ; i <= n ; i++) p[i] = i;
	
	
	for(int i = 1 ; i <= m ; i++)
	{
		int a,b;
		LL c;
		cin >> a >> b >> c;
		wu[idx].a = a,wu[idx].b = b,wu[idx++].w = c;
	}
	for(int i = 1 ; i <= k ;i++)
	{
		LL ww;
		cin >> ww;
		LL t[M] ={0};
		for(int j = 1; j <= n ; j++)
		{
			cin >> t[j];
		}
		for(int j = 1 ; j <= n; j++)
		{
			for(int k = j+1 ;k <= n;k++)
			{
				wu[idx].w = t[j]+t[k]+ww;
				wu[idx].a = j,wu[idx++].b = k;
			}
		}
	}
	
	sort(wu,wu+idx,cmp);
	
	/*for(int i = 0 ; i< idx; i++)
	{
		printf("从%d到%d建边需要%d\n",wu[i].a,wu[i].b,wu[i].w);
	}*/
	
	for(int i = 0 ; i < idx ; i++)
	{
		int a = wu[i].a , b = wu[i].b ;LL w = wu[i].w;
		if(!st[a]||!st[b]){
		//	printf("进行从%d到%d的建边,花费为%lld\n",a,b,w);
			ans+= w;
			st[a] = st[b] = true;
			int x = find(a) , y = find(b);
			p[y] = p[x];
		}
		else if(st[a]&&st[b])
		{
			int x = find(a) , y = find(b);
		//	printf("当前进入点:%d,%d;他们的祖宗:%d,%d",a,b,x,y);
			if(x!=y){
			//	printf("进行从%d到%d的建边,花费为%lld\n",a,b,w);
				ans+= w;
				p[y] = p[x];
			}
		}
	}
	
	cout << ans;
	
	
	
	return 0; 
}
