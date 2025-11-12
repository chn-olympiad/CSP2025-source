//SN-J00219唐一齐 西安市交大附中浐灞右岸学校
#include <bits/stdc++.h>
#define aa a[i]
#define b a[j]
#define c a[k]
#define d a[l]
using namespace std;
int n,a[5100],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i = 1;i<=n-2;i++)
		for(int j = i+1;j<=n-1;j++)
			for(int k = j+1;k<=n;k++)
				if(aa+b>c && aa+c>b && b+c>aa && aa-b<c && aa-c<b && b-aa<c && c-aa<b && b-c<aa && c-b<aa && (aa+b+c)>max({aa,b,c})*2)ans++;
	if(n == 4)
		for(int i = 1;i<=n-3;i++)
			for(int j = i+1;j<=n-2;j++)
				for(int k = j+1;k<=n-1;k++)
					for(int l = k+1;l<=n;l++)
						if((aa+b+d+c)>(max({aa,b,c,d})*2))ans++;
	cout<<ans;
	return 0;
}
