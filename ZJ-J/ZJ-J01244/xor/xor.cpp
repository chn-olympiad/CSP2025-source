#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],s[1048586],x[500010],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	memset(s,-1,sizeof s);
	s[0]=0;
	int t=0;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		x[i]=x[i-1]^a[i];
		if(s[x[i]^k]>=t)
		{
			t=i;
			ans++;
		}
		s[x[i]]=i;
	}
	cout << ans;
	return 0;
}

