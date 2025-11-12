#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int father[10005];

long long ans =0;

struct road{
	int u,v,w;
}a[1000005];

int c[15][10005];
bool cmp(road x,road y)
{
	if (x.w<y.w){
		return true;
	}
	return false;
}


int find_father(int a){
	if (father[a]==a) return a;
	father[a] = find_father(father[a]);
	return father[a];
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >>k;
	for (int i = 1; i<=n;i++)
	{
		father[i]=i;
	}
	for (int i = 1 ; i<= m;i++)
	{
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	
	bool is_a = true;
	for (int j = 1; j <= k ; j++)
	{
		for (int z = 0; z <=n; z++)
		{
			cin >> c[j][z];
			if (z == 0 && c[j][0] !=0 && is_a == true) is_a = false;  
		}
	}





	int tmp = m;
	
	for (int i = 1; i<=k;i++)
	{
		for (int j = 1;j<=n;j++)
		{
			for (int k = j+1;k<=n;k++)
			{
				tmp++;
				a[tmp].u=j;
				a[tmp].v=k;
				a[tmp].w=c[i][0]+c[i][j]+c[i][k];
			}
		}
	}
	
	sort(a+1,a+tmp+1,cmp);
	
	for (int i = 1;i<=tmp;i++)
	{
		int u = a[i].u;
		int v = a[i].v;
		int w = a[i].w;
		if (find_father(u)!=find_father(v))
		{
			father[find_father(v)] = find_father(u);
			ans+=w;
			
		}
	}
	cout << ans;
	return 0;
}