#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
struct node
{
	ll ai, aj, az;
	ll flag;
};
vector<node> a(1e3 + 10);
ll maxi, maxj, maxz;
ll n;
bool cmpi(node a, node b)
{
	return a.ai > b.ai;
}
bool cmpj(node a, node b)
{
	return a.aj > b.aj;
}
bool cmpz(node a, node b)
{
	return a.az > b.az;
}
ll imax()
{
	ll ans = 0;
	sort(a.begin(),a.end(), cmpi);
	a[0].flag = 1;
	ans += a[0].ai;
	if(maxj > maxz){
		sort(a.begin(),a.end(), cmpj);
		for(ll j = 0; j < n; j++){
			if(a[j].flag != 1){
				ans += a[j].aj;
				a[j].flag = 1;
				break;
			}
		}
		sort(a.begin(), a.end(), cmpz);
		for(ll j = 0; j < n; j++){
			if(a[j].flag != 1){
				ans += a[j].az;
				a[j].flag = 1;
				break;
			}
		}
	}
	else{
		sort(a.begin(),a.end(), cmpz);
		for(ll j = 0; j < n; j++){
			if(a[j].flag != 1){
				ans += a[j].az;
				a[j].flag = 1;
				break;
			}
		}
		sort(a.begin(), a.end(), cmpj);
		for(ll j = 0; j < n; j++){
			if(a[j].flag != 1){
				ans += a[j].aj;
				a[j].flag = 1;
				break;
			}
		}
	}
	return ans;
}
ll jmax()
{
	ll ans = 0;
	sort(a.begin(),a.end(), cmpj);
	a[0].flag = 1;
	ans += a[0].aj;
	if(maxi > maxz){
		sort(a.begin(),a.end(), cmpi);
		for(ll j = 0; j < n; j++){
			if(a[j].flag != 1){
				ans += a[j].ai;
				a[j].flag = 1;
				break;
			}
		}
		sort(a.begin(), a.end(), cmpz);
		for(ll j = 0; j < n; j++){
			if(a[j].flag != 1){
				ans += a[j].az;
				a[j].flag = 1;
				break;
			}
		}
	}else{
		sort(a.begin(),a.end(), cmpz);
		for(ll j = 0; j < n; j++){
			if(a[j].flag != 1){
				ans += a[j].az;
				a[j].flag = 1;
				break;
			}
		}
	}
	return ans;
}
ll zmax()
{
	ll ans = 0;
	sort(a.begin(),a.end(), cmpz);
	a[0].flag = 1;
	ans += a[0].az;
	if(maxi > maxj){
		sort(a.begin(),a.end(), cmpi);
		for(ll j = 0; j < n; j++){
			if(a[j].flag != 1){
				ans += a[j].ai;
				a[j].flag = 1;
				break;
			}
		}
		sort(a.begin(), a.end(), cmpj);
		for(ll j = 0; j < n; j++){
			if(a[j].flag != 1){
				ans += a[j].aj;
				a[j].flag = 1;
				break;
			}
		}
	}else{
		sort(a.begin(),a.end(), cmpj);
		for(ll j = 0; j < n; j++){
			if(a[j].flag != 1){
				ans += a[j].aj;
				a[j].flag = 1;
				break;
			}
		}
		sort(a.begin(), a.end(), cmpi);
		for(ll j = 0; j < n; j++){
			if(a[j].flag != 1){
				ans += a[j].ai;
				a[j].flag = 1;
				break;
			}
		}
	}
	return ans;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	for(ll i = 0; i < t; i++)
	{
		n = 0;
		maxi = 0;
		maxj = 0,
		maxz = 0;
		cin >> n;
		for(ll j = 0; j < n; j++)
		{
			cin >> a[j].ai >> a[j].aj >> a[j].az;
			maxi = max(a[j].ai, maxi);
			maxj = max(a[j].aj, maxj);
			maxz = max(a[j].az, maxz);
		}
		if(maxj == 0 ||maxz == 0)
		{
			sort(a.begin(), a.end(), cmpi);
			ll ans = 0;
			for(ll i = 0; i < (n/2); i++)
			{
				ans += a[i].ai;
			}
			cout << ans << '\n';
			continue;
		}
		ll res = n;
		ll ans = 0;
		while(res != 0)
		{
			maxi = 0;
			maxj = 0,
			maxz = 0;
			if(res / 3 >= 1)
			{
				for(ll j = 0; j < n; j++)
				{
					if(a[j].flag == 1) continue;
					maxi = max(maxi, a[j].ai);
					maxj = max(a[j].aj, maxj);
					maxz = max(a[j].az, maxz);
				}
				if((maxi >= maxj) || (maxi >= maxz)) ans += imax();
				else if((maxj >= maxi) || (maxj >= maxz)) ans += jmax();
				else ans += zmax();
				res -= 3;
			}
			else if(res % 3 == 2)
			{
				ll cnt = 0;
				for(ll j = 0; j < n; j++)
				{
					if(a[j].flag != 1)
					{
						a[cnt] = a[j];
						cnt++;
					}
					if(cnt == 1) break;
				}
				ll cas1 = a[0].ai + a[1].aj;
				ll cas2 = a[0].ai + a[1].az;
				
				ll cas3 = a[0].aj + a[1].az;
				ll cas4 = a[0].aj + a[1].ai;
				
				ll cas5 = a[0].az + a[1].ai;
				ll cas6 = a[0].az + a[1].aj;
				
				ans += max(cas1, max(cas2, max(cas3, max(cas4, max(cas5, cas6)))));
				cout << ans << '\n';
				res -= 2;
				break;
			}
			else if(res % 3 == 1)
			{
				for(ll j = 0; j < n; j++)
				{
					if(a[j].flag != 1){
						ans += max(a[j].ai, max(a[j].aj, a[j].az));
						break;
					}
				}
				cout << ans << '\n';
				res -= 1;
				break;
			}
		}
	}
	return 0;
}
