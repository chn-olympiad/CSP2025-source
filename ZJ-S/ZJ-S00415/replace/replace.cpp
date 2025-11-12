#include <bits/stdc++.h>
//#define int long long
using namespace std;
int n,q,ans;
string A[200005],B[200005],L,R,X;
//struct Tire
//{
//	int t[5000005][30],l,f[5000005];
//	void add(string x)
//	{
//		int p=0;
//		for(int i=0;x[i];i++)
//		{
//			if(!t[p][x[i]-'a'])t[p][x[i]-'a']=++l;
//			p=t[p][x[i]-'a'];
//		}
//	}
//}T;
bool check(int p,string A)
{
	for(int i=p,j=0;A[j];i++,j++)
	{
//		cout<<L[i]<<" "<<A[j]<<"\n";
		if(L[i]!=A[j])return false;
	}
	return true;
}
void Check(string A,string B)
{
//	cout<<A<<" "<<B<<"\n";
	for(int j=0;L[j];j++)
	{
		if(!check(j,A))continue;X=L;
//		cout<<j<<" ";
//		cout<<"\n";
		for(int I=j,J=0;B[J];I++,J++)X[I]=B[J];
//		cout<<X<<"\n";
		if(X==R)ans++;
	}
//	cout<<"\n";
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>A[i]>>B[i];
	while(q--)
	{
		cin>>L>>R;
		for(int i=1;i<=n;i++)Check(A[i],B[i]);
		cout<<ans<<"\n";ans=0;
	}
	return 0;
}

