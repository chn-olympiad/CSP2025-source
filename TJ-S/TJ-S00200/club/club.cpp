#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read()	
{			
	ll f = 1, sum = 0; char c = getchar();
	while(c < '0' || c > '9')
	{	
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') sum = (sum << 1) + (sum << 3) + (c ^ 48), c = getchar();
	return sum * f;
}
const ll N = 2e5 + 10;
ll T;
ll n, a[N][4], b[N][4], sum, now[N];
priority_queue<ll>q;
bool cmp(ll a, ll b)
{
	return a > b;
}
void solve()
{
	n = read();
	sum = 0;
	for(int i = 1; i <= n; i++) a[i][1] = read(), a[i][2] = read(), a[i][3] = read();
	for(int i = 1; i <= n; i++) 
		sum += a[i][1], b[i][1] = 0, b[i][2] = a[i][2] - a[i][1], b[i][3] = a[i][3] - a[i][1];
	ll flag = 0;
	for(int i = 1; i <= n; i++)
	{
		if(b[i][2] >= 0 || b[i][3] >= 0) flag++;
	}  
	if(flag <= n / 2) // 如果少于n / 2, 说明如果直接对B和C做A是不可以的 
	{
//		cout<<"A!"<<"\n";
		while(!q.empty()) q.pop();
		for(int i = 1; i <= n; i++) q.push(max(b[i][3], b[i][2]));
		for(int i = 1; i <= n / 2; i++) sum += q.top(), q.pop();
		cout<<sum<<"\n";
		return ;
	} 
	else// 否则直接对B和C做的结果一定 >= n / 2 
	{
		ll ans = 0;
		ll numb = 0, numc = 0;
		for(int i = 1; i <= n; i++)
		{
			if(b[i][3] < 0 && b[i][2] < 0) continue;
			if(b[i][3] > b[i][2]) numc++;// 第三行的更大 
			else if(b[i][3] < b[i][2]) numb++;
			else numc++, numb++;
		}
//		cout<<"---"<<numb<<" "<<numc<<"\n";
		if(numc >= n / 2) // c多出来了 
		{
//			cout<<"C!"<<"\n";
			for(int i = 1; i <= n; i++)
			{
				if((b[i][3] < 0 && b[i][2] < 0)) continue; 
				if(b[i][3] < b[i][2]) ans += b[i][2];
			}
			ll nsum = 0, cnt = 0;
			for(int i = 1; i <= n; i++)// 起码有一个大于0, c还比b大, 那c >= 0 
			{
				if((b[i][3] < 0 && b[i][2] < 0)) continue;
				if(b[i][3] < b[i][2]) continue;
				nsum = nsum + b[i][3]; now[++cnt] = max(0 * 1ll, b[i][2]) - b[i][3];
			}
			sort(now + 1, now + cnt + 1, cmp);
			for(int i = 1; i <= cnt - n / 2; i++) nsum += now[i];
			ans += nsum;
			cout<<sum + ans<<"\n";
		}
		else if(numb >= n / 2)
		{
//			cout<<"B!"<<"\n"; 
			for(int i = 1; i <= n; i++)
			{
				if((b[i][3] < 0 && b[i][2] < 0)) continue; 
				if(b[i][3] > b[i][2]) ans += b[i][3];
			}
			ll nsum = 0, cnt = 0;
			for(int i = 1; i <= n; i++)// 起码有一个大于0, b还比c大, 那b >= 0 
			{
				if((b[i][3] < 0 && b[i][2] < 0)) continue;
				if(b[i][3] > b[i][2]) continue;
				nsum = nsum + b[i][2]; now[++cnt] = max(0 * 1ll, b[i][3]) - b[i][2];
			}
			sort(now + 1, now + cnt + 1, cmp);
			for(int i = 1; i <= cnt - n / 2; i++) nsum += now[i];
			ans += nsum;
			cout<<sum + ans<<"\n";
		}
		else
		{
//			cout<<"B&C!"<<"\n";
			for(int i = 1; i <= n; i++) 
			{
				if((b[i][3] < 0 && b[i][2] < 0)) continue;
				ans = ans + max(b[i][2], b[i][3]);
			}
			cout<<ans + sum<<"\n";
		}
	} 
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T = read();
	while(T--) solve();
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
