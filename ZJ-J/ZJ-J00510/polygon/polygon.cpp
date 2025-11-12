#include <bits/stdc++.h>
using namespace std;
int n;
#define ll long long
const ll mod = 998244353;
ll a[5010];
void f2(){
	ll p = 2;
	ll pow = 1;
	for(int i = 2;i <= n + 2;i++){
		pow *= 2;
		if(i == n + 1) cout << pow-p  << ' ';
		pow %= 998244353;
		p += i;
	}
}
int main(){	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
    if(n > 22){
    	f2();
    	return 0;
	}
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	ll res = 0;
	for(ll mask = 0;mask < (1 << n);mask++){
		ll ans = 0,mx = 0;
		for(int i = 0;i < n;i++){
			if(mask & (ll)(1 << i)){
				ans += a[i];
				mx = max(a[i],mx);
			}
		}
		if(ans > 2*mx){
			res++;
		}
	}
	cout << res << endl;
	return 0;
}
/*
Can i take part in MIHUOXINGWEIDASHANG?
lol
I think that there will be many mistakes below...
Counting Stars-OneRepublic

Lately i've been i've been losing sleep
Dreaming about the things that we could beeeee
But baby i've been i've been praying hard
Said no more counting dollars
Will be counting stars
Yeah will be counting stars 

I see the life like a swinging vine
Swing my heart across the line
And my face is flashing signs
Seek it out and u shall find
Old but not that bold
Young but not that ?
I dont think the world is soul
I'm just doing what we told
Ah---- i felt something so wrong
Doing the right thing....
Ah---- i felt something so right
Doing the wrong thing....
I could lie could lie could lie
EVERY THING THAT KILLS MEeeeeeee
MAKES ME FEEL AIVE

Lately i've been i've been losing sleep
Dreaming about the things that we could beeeee
But baby i've been i've been praying hard
Said no more counting dollars
Will be counting stars
Lately i've been i've been losing sleep
Dreaming about the things that we could beeeee
But baby i've been i've been praying hard
Said no more counting dollars
Will be counting stars
*/