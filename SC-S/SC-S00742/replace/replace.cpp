#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n, q;
struct node
{
	string a;
	string b;
}A[200002];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++)
	{
		cin>>A[i].a>>A[i].b;
	}
	int num=0;
	while(q--)
	{
		string bg, goal, tmp1, tmp2;
		cin>>bg>>goal;
		int len=bg.size();
		if(goal.size()!=len)
		{
			cout<<"0\n";
			continue;
		} 
		bg='('+bg, goal='('+goal;
		if(bg==goal)
		{
			ll anss=0;
			for(int i=1; i<=n; i++)
			{
				if(A[i].a==A[i].b)
				{
					anss++;
				}
			}
			cout<<anss<<"\n";
			continue;
		}
		bool dif=0;
		int l, r;
		for(int i=1; i<=len; i++)
		{
			if(bg[i]!=goal[i] && !dif)
			{
				l=i;
				dif=1;
				tmp1=bg[i], tmp2=goal[i];
			}
			if(bg[i]!=goal[i])
			{
				r=i;
			}
		}
		for(int i=l+1; i<=r; i++)
		{
			tmp1=tmp1+bg[i];
			tmp2=tmp2+goal[i];
		}
		
	//	cout<<tmp1<<" "<<tmp2<<endl;
		
		ll ans=0;
		for(int i=1; i<=n; i++)
		{
			bool ok=1;
			string t1=A[i].a, t2=A[i].b;
			if(t1.find(tmp1)!=-1)
			{
				int st=l-(t1.find(tmp1));
			//	cout<<i<<" "<<st<<" "<<st+t1.size()-1<<endl;
				if(st<1 || st+t1.size()-1>len)
				{
					continue;
				}
				int jj=0;
				for(int j=st; j<=st+t1.size()-1; j++)
				{
					if(bg[j]==t1[jj] && goal[j]==t2[jj])
					{
					}else
					{
						ok=0;
						break;
					}
					jj++;
				}
				if(ok)
				{
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
