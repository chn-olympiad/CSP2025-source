#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005],b[100005],c[100005];
int maxxx = 0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >>t;
	while(t--){
		cin>> n;
		for(int i = 0;i<n;i++)
		{
			cin >>a[i];
		}
		for(int i = 0;i<n;i++)
		{
			cin >>b[i];
		}
		for(int i = 0;i<n;i++)
		{
			cin >>c[i];
		}
		int m = n/2;
		int maxx = 0;
		int cnt = 0;
		int ans = 0;
		int sum = 0;
		long long d  =0;
		int f = 0;
		int ff = 0;
		int fff = 0;
		for(int i = 0;i<n;i++)
		{
			if(maxx<a[i])
			{
				maxx = a[i];
		    }
			if(maxx<b[i])
			{
				maxx = b[i];
			}
			if(maxx<c[i])
			{
				maxx = c[i];
			} 
			if(maxx == a[i]&&f == 0)
			{
				if(sum>=m)
				{
					if(maxxx<=b[i]&&ff == 0)
					{
						maxxx = b[i];
						ans++;
						d+=b[i];
						maxxx = 0;
					}
					else if(maxxx<=c[i]&&fff == 0)
					{
						maxxx = c[i];
						cnt++;
						d+=c[i];
						maxxx = 0;
					}
					f = 1;
					continue;
				}
				sum++;
		        d+=a[i];		
			}
			if(maxx == b[i]&&ff == 0)
			{
				if(ans>=m)
				{
					if(maxxx<a[i]&&f == 0)
					{
						maxxx = a[i];
						sum++;
						d+= a[i];
						maxxx =0;
					}
					else if(maxxx<=c[i]&&fff == 0)
					{
						maxxx = c[i];
						cnt++;
						d+=c[i];
						maxxx = 0;
					}
					ff = 1;
					continue;
				}
			}
			if(maxxx = c[i]&fff == 0){
				if(cnt>=m)
				{
					if(maxxx<a[i]&&f == 0)
					{
						maxxx = a[i];
						sum++;
						d+= a[i];
						maxxx =0;
					}
					else if(maxxx<=b[i]&&ff == 0)
					{
						maxxx = b[i];
						ans++;
						d+=b[i];
						maxxx = 0;
					}
					fff = 1;
					continue;
				}
			}
		}
		cout <<d<<endl;
	}
	return 0;
}
