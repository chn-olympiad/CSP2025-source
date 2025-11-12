#include <bits/stdc++.h>
using namespace std;
long long n, m, k, c[105], to[105][10005], L, R, fa[10005], a[1005][1005], faL, faR; 
struct ROAD 
{
	long long left, right, num;
}road[10000005];

long long find(long long x)
{
	if (fa[x] == x) return x;
	fa[x] = find(fa[x]);
	return fa[x];
}

bool cmp (ROAD A, ROAD B)
{
	return A.num < B.num;
}
int main()
{
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m >> k;
    if (k == 0)
	{
		for (register int i = 1; i <= m; ++ i)
	    {
	    	cin >> road[i].left >> road[i].right >> road[i].num;
	    }
	    for (register int i = 1; i <= n; i ++) fa[i] = i;
	    sort (road + 1, road + m + 1, cmp);
	    long long ans = 0;
	    for (register int i = 1; i <= m; ++ i)
	    {   
	    	L = road[i].left;
	    	R = road[i].right;
	    	if (find(L) != find(R))
		    {
			    fa[find(L)] = find(R);
			    ans += road[i].num;
		    }
	    }
	    cout << ans << endl;
	} 
    else
    {
    	for (register int i = 1;i <= m; ++ i)
    	{
    		cin >> road[i].left >> road[i].right >> road[i].num;
    		a[road[i].left][road[i].right] = 1ll;
    		a[road[i].right][road[i].left] = 1ll;
		}
		for (register int i = 1; i <= n; ++ i) fa[i] = i;
		for (register int i = 1; i <= k; ++ i)
		{
			cin >> c[i];
			for (register int j = 1; j <= n; ++ j)
			{
				cin >> to[i][j];
			}
		}
		for (register int i = 1; i <= m; ++ i)
		{
			for (register int j = 1; j <= k; ++ j)
			{
				road[i].num = min (road[i].num, 0ll + c[j] + to[j][road[i].left] + to[j][road[i].right]);
			}
		}
		for (register int i = 1; i <= n; ++ i)
		{
			for (register int j = i + 1; j <= n; ++ j)
			{
				if (!a[i][j])
			    {road[++m].left = i;
			    road[m].right = j;
			    road[m].num = 1e18;
			    	for (register int aa = 1; aa <= k; ++ aa){
			    		road[m].num = min (road[m].num, 0ll + c[aa] + to[aa][i] + to[aa][j]);
					} 
				}
			}
		}
		sort (road + 1, road + m + 1, cmp);
		long long ans = 0ll;
		for (register int i = 1; i <= m; ++ i)
		{
		    L = road[i].left;
			R = road[i].right;
			faL = find(L);
			faR = find(R);
			if (faL - faR != 0)
			{
				ans += road[i].num;
				fa[faL] = faR; 
			}
		}
		cout << ans << endl;
	}
	return 0;
}

 /*
 CCF I love you  CCF I love you  CCF I love you  CCF I love you  依旧诈如骗 
 
 
 《star sky》

Here we are riding the sky

Painting the night with the sun

You and I mirrors of light 

Twin flames of fire lit in another time and place

I knew your name I knew your face

You love and grace

Past and present cannot embrace

World collide in inner space

Unstoppable the song we play

Burn the page for me

I cannot erase the time of sleep

I cannot be love so set me free

I cannot deliver your love or caress your soul so

Turn that page for me

I cannot embrace the touch that you give

I cannot find sloace in your words

I cannot deliver you your love

Or caress your soul


Age to age I feel the call

Memory of future dreams

You and I riding the sky

Keeping the fire bright 

From another time and place

I know your name I know your face

Your touch and grace

All of time cannot erase

What we hearts remember stays

Forever the song we play

Burn the page for me

I cannot erase the time of sleep

I cannot be love so set me free

I cannot deliver your love or caress your soul so

Turn that page for me

I cannot embrace the touch that you give

I cannot find sloace in your words

I cannot deliver you your love

Or caress your soul
 
可以听一下，很好听。 
*/
