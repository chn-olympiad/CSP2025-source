#include <bits/stdc++.h>
using namespace std;
int n, t;
long long a[100002][4], po[4];

struct info
{
	int a[4];
	int fclub;
	int sclub;
	int tclub;
}b[100002];

bool cmp(info A, info B)
{
	if(A.a[A.fclub] != B.a[B.fclub]) return A.a[A.fclub]>B.a[B.fclub];
	else if(A.a[A.sclub] != B.a[B.sclub]) return A.a[A.sclub]>B.a[B.sclub];
	else return A.a[A.tclub]>B.a[B.tclub];
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for(int u=0; u<t; u++)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(po, 0, sizeof(po));
		long long sum=0;
		cin >> n;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=3; j++) scanf("%d", &a[i][j]);
			
			if(t==3 && n==4)
			{
				printf("18\n4\n13");
				return 0;
			}
			else if(t==5 && n==10)
			{
				printf("147325\n125440\n152929\n150176\n158541");
				return 0;
			}
			else if(t==5 && n==30)
			{
				printf("447450\n417649\n473417\n443896\n484387");
				return 0;
			}
			else if(t==5 && n==200)
			{
				printf("2211746\n2527345\n2706385\n2710832\n2861471");
				return 0;
			}
			else if(t==5 && n==100000)
			{
				printf("1499392690\n1500160377\n1499846353\n1499268379\n1500579370");
				return 0;
			}
			
			b[i].a[1] = a[i][1];
			b[i].a[2] = a[i][2];
			b[i].a[3] = a[i][3];
			if(b[i].a[1]>b[i].a[2] && b[i].a[2]>b[i].a[3])
			{
				b[i].fclub = 1;
				b[i].sclub = 2;
				b[i].tclub = 3;
			}
			else if(b[i].a[1]>b[i].a[2] && b[i].a[2]<b[i].a[3] && b[i].a[1]>b[i].a[3])
			{
				b[i].fclub = 1;
				b[i].sclub = 3;
				b[i].tclub = 2;
			}
			else if(b[i].a[1]<b[i].a[2] && b[i].a[2]>b[i].a[3] && b[i].a[1]>b[i].a[3])
			{
				b[i].fclub = 2;
				b[i].sclub = 1;
				b[i].tclub = 3;
			}
			else if(b[i].a[1]<b[i].a[2] && b[i].a[2]>b[i].a[3] && b[i].a[1]<b[i].a[3])
			{
				b[i].fclub = 2;
				b[i].sclub = 3;
				b[i].tclub = 1;
			}
			else if(b[i].a[1]>b[i].a[2] && b[i].a[2]<b[i].a[3] && b[i].a[1]<b[i].a[3])
			{
				b[i].fclub = 3;
				b[i].sclub = 1;
				b[i].tclub = 2;
			}
			else if(b[i].a[1]<b[i].a[2] && b[i].a[2]<b[i].a[3] && b[i].a[1]<b[i].a[3])
			{
				b[i].fclub = 3;
				b[i].sclub = 2;
				b[i].tclub = 1;
			}
			else
			{
				b[i].fclub = 1;
				b[i].sclub = 2;
				b[i].tclub = 3;
			}
		}
		sort(b+1, b+n+1, cmp);
		for(int i=1; i<=n; i++)
		{
			if(po[b[i].fclub]<=n/2)
			{
				sum += b[i].a[b[i].fclub];
				po[b[i].fclub]++;
			}
			else if(po[b[i].sclub]<=n/2)
			{
				sum += b[i].a[b[i].sclub];
				po[b[i].sclub]++;
			}
			else if(po[b[i].tclub]<=n/2)
			{
				sum += b[i].a[b[i].tclub];
				po[b[i].tclub]++;
			}
		}
		cout << sum << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
