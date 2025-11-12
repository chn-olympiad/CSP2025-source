#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s1[N],s2[N];
string chg1[N],chg2[N];
string l1,l2,frm,to;
int n,q;
int L[N],R[N],len[N],Len;
vector<int> upd[5000005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cin.tie(0);
	cin>>n>>q;
	for(int i=1,l,r;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
//		cout<<s1[i].size()<<' '<<s2[i].size()<<'\n';
		l=0,r=s1[i].size()-1;
		len[i]=r+1;
		if(s1[i]==s2[i])
		{
			L[i]=0,R[i]=0;
			chg1[i]=chg2[i]="";
			continue;
		}
		while(s1[i][l]==s2[i][l]) l++;
		while(s1[i][r]==s2[i][r]) r--;
		L[i]=l,R[i]=r;
		chg1[i]=string(s1[i],l,r-l+1),chg2[i]=string(s2[i],l,r-l+1);
		upd[r-l+1].emplace_back(i);
//		cout<<i<<' ';
	}
	int l,r,ans=0;
	while(q--)
	{
		cin>>l1>>l2;
		l=0,r=l1.size()-1;
		Len=r+1;
		while(l1[l]==l2[l]) l++;
		while(l1[r]==l2[r]) r--;
		frm=string(l1,l,r-l+1),to=string(l2,l,r-l+1);
		ans=0;
		if(!upd[r-l+1].empty()) for(auto i:upd[r-l+1]) if(frm==chg1[i]&&to==chg2[i]&&l>=L[i]&&l-L[i]+len[i]-1<Len&&string(l1,l-L[i],len[i])==s1[i]) ans++;
		cout<<ans<<'\n';
	}
	return 0;
}