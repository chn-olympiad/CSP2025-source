#include<bits/stdc++.h>
using namespace std;
int n,k,s,lst,ans;
const int N=(1<<20)+10;
int a[N],b[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(b,-1,sizeof(b));
	s=0;b[s]=0;lst=0;	
	for(int i=1;i<=n;i++)
    {
    	s^=a[i];
//		cout<<i<<" "<<s<<" "<<lst<<'\n';
    	if(b[s^k]>=lst)
    	{
    		ans++;
    		lst=i;
		}
		b[s]=i;
	}
	cout<<ans;
	return 0;
}