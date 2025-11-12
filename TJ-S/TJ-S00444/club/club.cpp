#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+100;
int t;
int n;

struct stu
{
	int a;
	int b;
	int c;
	int like;//志愿值 
}stus[MAXN];

bool cmp(stu x,stu y)
{
	return x.like > y.like;
}

struct wil
{
	int ind;
	int val;
}wils[105];

bool cmp2(wil x,wil y)
{
	return x.val > y.val;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>t;
	for(int ttt=1;ttt<=t;++ttt)
	{
		cin>>n;
		long long res = 0;
		for(int i=1;i<=n;++i)//S1输入和求基准值 
		{
			int a,b,c;
			cin>>a>>b>>c;
			int delta = min(a,min(b,c));
			int za = a - delta;
			int zb = b - delta;
			int zc = c - delta;
			stus[i].a = a;
			stus[i].b = b;
			stus[i].c = c;
			int temp[4] = {a,b,c};
			sort(temp,temp+3);
			stus[i].like =  temp[2] - temp[1];
			
		}
		//S2排序
		sort(stus+1,stus+1+n,cmp);
		//S3由高到低录取
		int cntA = 0;
		int cntB = 0;
		int cntC = 0;
		
		int cnt[5] = {0,0,0,0,0};
		for(int i=1;i<=n;++i)
		{
			wils[1].ind = 1;
			wils[2].ind = 2;
			wils[3].ind = 3;
			wils[1].val = stus[i].a;
			wils[2].val = stus[i].b;
			wils[3].val = stus[i].c;
			sort(wils+1,wils+1+3,cmp2);
			//cout<<i<<" "<<wils[1].val<<" "<<wils[2].val<<" "<<wils[3].val<<endl;
			for(int j=1;j<=3;++j)
			{
				int curClub = wils[j].ind;
				if(cnt[curClub]<n/2)
				{
					cnt[curClub]++;
					res += wils[j].val;
					//cout<<i<<" "<<curClub<<endl;
					//cout<<wils[1].val<<" "<<wils[2].val<<" "<<wils[3].val<<" "<<j<<endl;
					break;
				} 
			}
		} 
		cout<<res<<'\n';
	}
	return 0;
}  
