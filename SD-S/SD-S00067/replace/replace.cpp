#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,m;
struct xieyin{
	string t1;
	string t2;
};
string cac;
xieyin xxy[200010];
string a;
string b;
int main(){
	freopen("replace1.in","r",stdin);
	freopen("replace1.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	int n,q;
	ll co=0;
	cin>>n>>q;
	for(int i=0;i<n;i++)
    {
    	cin>>xxy[i].t1>>xxy[i].t2;
	}
	for(int i=0;i<q;i++)
	{
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<endl;
			continue;
		}
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<a.size()-xxy[j].t1.size();k++)
			{
				for(int l=0;l<xxy[j].t1.size();l++)
				{
					if(xxy[j].t1[l]!=a[k])
					{
						break;
					}
					cac=a;
					for(int r=k;r<k+xxy[j].t1.size();r++)
					{
						cac[r]=xxy[j].t2[r-k];
					}
					if(cac==b)
					{
						co++;
					}
				}
			}
		}
		cout<<co;
		co=0;
	}
	return 0;
}

