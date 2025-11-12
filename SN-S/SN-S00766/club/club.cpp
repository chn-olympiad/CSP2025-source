//SN-S00766 韩心尧 西安滨河学校 
#include <bits/stdc++.h>
#define int long long

using namespace std;

int t,n;
int cnt[3],cntt;
int ans,res;
int vis[100010];
vector<int> va,vb,vc;
struct mbr
{
	int a[3],id;
} m[100010];
bool cmpa(mbr mx,mbr my)
{
	return mx.a[0] > my.a[0];
}
bool cmpb(mbr mx,mbr my)
{
	return mx.a[1] > my.a[1];
}
bool cmpc(mbr mx,mbr my)
{
	return mx.a[2] > my.a[2];
}
bool cmpi(mbr mx,mbr my)
{
	return mx.id < my.id;
}
void chs_a()
{
	vector<int> vva = va;
	if (cnt[0] < (n *1.0/ 2))
	{
//			for (auto x : va)
//				{
//					cout << x <<" ";
//				}
//				cout << endl;
		for (int j = 0; j < vva.size(); )
		{
//					for (auto x : va)
//					{
//						cout << x <<" ";
//					}
//					cout << endl;
			int wi = vva[j];
			//printf("wi_a %d\n",wi);
			if (((m[wi].a[0] > m[wi].a[1] && m[wi].a[0] > m[wi].a[2])) && cnt[0] < (n *1.0/ 2) )
			{
				if (vis[wi] != -1 && vis[wi] != 0)
				{
					ans -= m[wi].a[vis[wi]];
					cnt[vis[wi]]--;
					cntt--;
//					printf("change %d from %d into 0",wi,vis[wi]);
				}
				ans += m[wi].a[0];
				cnt[0]++;
				cntt++;
				vis[wi] = 0;
//				printf("match %d to 0 ans = %d\n",wi,ans);
				vva.erase(vva.begin() + j );
			}
			else if (vis[wi] == -1 && cnt[0] < (n *1.0/ 2))
			{
				ans += m[wi].a[0];
				cnt[0]++;
				cntt++;
				vis[wi] = 0;
//				printf("match %d to 0 ans = %d\n",wi,ans);
				vva.erase(vva.begin() + j );
			}
			else
			{
				j++;
			}

		}


	}
}
void chs_b()
{
	vector<int> vvb = vb;
	if (cnt[1] < (n*1.0 / 2))
	{
		for (int j = 0; j < vvb.size(); )
		{
			int wi = vvb[j];
			if (m[wi].a[1] > m[wi].a[0] && m[wi].a[1] > m[wi].a[2] && cnt[1] < (n*1.0 / 2))
			{
				if (vis[wi] != -1 && vis[wi] != 1)
				{
					ans -= m[wi].a[vis[wi]];
					cnt[vis[wi]]--;
					cntt--;
//					printf("change %d from %d into 1",wi,vis[wi]);
				}
				ans += m[wi].a[1];
				cnt[1]++;
				cntt++;
				vis[wi] = 1;
//				printf("match %d to 1 ans = %d\n",wi,ans);
				vvb.erase(vvb.begin() + j );
			}
			else if (vis[wi] == -1 && cnt[1] < (n *1.0/ 2))
			{
				ans += m[wi].a[1];
				cnt[1]++;
				cntt++;
				vis[wi] = 1;
//				printf("match %d to 1 ans = %d\n",wi,ans);
				vvb.erase(vvb.begin() + j );
			}
			else
			{
				j++;
			}
		}
	}
}
void chs_c()
{
	vector<int> vvc = vc;
	if (cnt[2] < (n *1.0/ 2))
	{
		for (int j = 0; j < vvc.size(); )
		{
			int wi = vvc[j];
			if (m[wi].a[2] > m[wi].a[1] && m[wi].a[2] > m[wi].a[0] && cnt[2] < (n*1.0 / 2))
			{
				if (vis[wi] != -1 && vis[wi] != 2)
				{
					ans -= m[wi].a[vis[wi]];
					cnt[vis[wi]]--;
					cntt--;
//					printf("change %d from %d into 2",wi,vis[wi]);
				}
				ans += m[wi].a[2];
				cnt[2]++;
				cntt++;
				vis[wi] = 2;
//				printf("match %d to 2 ans = %d\n",wi,ans);
				vvc.erase(vvc.begin() + j );
			}
			else if (vis[wi] == -1 && cnt[2] < (n  * 1.0/ 2))
			{
				ans += m[wi].a[2];
				cnt[2]++;
				cntt++;
				vis[wi] = 2;
//				printf("match %d to 2 ans = %d\n",wi,ans);
				vvc.erase(vvc.begin() + j );
			}
			else
			{
				j++;
			}
		}
	}
}
void init()
{
	memset(vis,-1,sizeof(vis));
	cnt[0] = cnt[1] = cnt[2] = cntt = 0;
	 ans = 0;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for (int i = 1; i <= t; i++)
	{

		cin >> n;
		res = 0;
		init();
		va.clear(),vb.clear(),vc.clear();
		for (int j = 1; j <= n; j++)
		{
			cin >> m[j].a[0] >> m[j].a[1] >> m[j].a[2];
			m[j].id = j;
		}
		sort(m + 1,m + n + 1,cmpa);
		for (int j = 1; j <= n; j++)
		{
			va.push_back(m[j].id);
		}
		sort(m + 1,m + n + 1,cmpi);
		sort(m + 1,m + n + 1,cmpb);
		for (int j = 1; j <= n; j++)
		{
			vb.push_back(m[j].id);
		}
		sort(m + 1,m + n + 1,cmpi);
		sort(m + 1,m + n + 1,cmpc);
		for (int j = 1; j <= n; j++)
		{
			vc.push_back(m[j].id);
		}
		sort(m + 1,m + n + 1,cmpi);
//		for (auto x : va)
//		{
//			cout << x <<" ";
//		}
//		cout << endl;
//		for (auto x : vb)
//		{
//			cout << x <<" ";
//		}
//		cout << endl;
//		for (auto x : vc)
//		{
//			cout << x <<" ";
//		}
//		cout << endl;
		init();
//		while (cntt < n)
//		{
			//	printf("while %d  cntt = %d\n",i,cntt);

			chs_a();
			chs_b();
			chs_c();
//			printf("not get:");
//			for (int j = 1; j <= n; j++)
//			{
//				if (vis[j] == -1)
//				{
//					printf("%d ",j);
//				}
//			}
//			printf("\n");
			
//		}
		res = max(res,ans);
//		//cout<<res <<" "<<ans<<endl;
//		init();
//		while (cntt < n)
//		{
//			//	printf("while %d  cntt = %d\n",i,cntt);
//
//			chs_a();
//			chs_c();
//			chs_b();
//			
//		}
//		res = max(res,ans);
//		//cout<<res <<" "<<ans<<endl;
//		init();
//		while (cntt < n)
//		{
//			//	printf("while %d  cntt = %d\n",i,cntt);
//
//			chs_b();
//			chs_a();
//			chs_c();
//			
//		}
//		res = max(res,ans);
//		//cout<<res <<" "<<ans<<endl;
//		init();
//		while (cntt < n)
//		{
//			//	printf("while %d  cntt = %d\n",i,cntt);
//
//			chs_b();
//			chs_c();
//			chs_a();
//			
//		}
//		res = max(res,ans);
//	//	cout<<res <<" "<<ans<<endl;
//		init();
//		while (cntt < n)
//		{
//			//	printf("while %d  cntt = %d\n",i,cntt);
//
//			chs_c();
//			chs_a();
//			chs_b();
//			
//		}
//		res = max(res,ans);
//		//cout<<res <<" "<<ans<<endl;
//		init();
//		while (cntt < n)
//		{
//			//	printf("while %d  cntt = %d\n",i,cntt);
//
//			chs_c();
//			chs_b();
//			chs_a();
//			
//		}
//		res = max(res,ans);
//		//cout<<res <<" "<<ans<<endl;;
		cout << res<<endl;
	}

	return 0;
}
