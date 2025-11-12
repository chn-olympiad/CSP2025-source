#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int p = 998244353;


int a[5005];
ll dp[5005][5005];
ll ans[5005];
signed main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    //cout << 5005*5005 << endl;
    //cout << 512 * 1024 * 1024 / 4 << endl;
    int n;cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int mx = a[n];
    dp[0][0] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= mx; j++) {
            if (!dp[i][j])continue;
            //cout << i << ":" << j << " " << dp[i][j] << endl;
            if (j <= a[i + 1]) {
                ans[i] += dp[i][j];
                ans[i] %= p;
            }
            if (j + a[i + 1] <= mx) {
                dp[i + 1][j + a[i + 1]] += dp[i][j];
                dp[i + 1][j + a[i + 1]] %= p;
            }
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= p;
        }
    }
    ll sum = 0;
    ll pw = 2;
    for (int i = 3; i <= n; i++) {
        pw *= 2;pw %= p;
        //cout << i << " " << pw << " " << ans[ i- 1] << endl;
        sum += (((pw - ans[i - 1]) % p) + p) % p;
        sum %= p;
    }
    cout << sum;
    return 0;
}

/*
my :   25050025 type
512MB :134217728 type

very enough
*/






/*

//freopen("", "r", stdin);
//freopen("", "w", stdout);

freopen("", "w", stdin);
freopen("", "r", stdout);
mian()
y1
nailong 114514 1919810
chen_zhe cz kkksc03

(**catch you!**)


Grade 9 OIer
Luogu uid: 474470
QQ: forget  D:
Wechat: wizardMarshall62442


article:

8:50
use 20min to get 300pts

8:55 
I know how T4(?)

9:00

I don't know D:
only get 17*4=68pts

That's okay, still have 3 hours

9:08

I know.


9:22

AK.

10:00

Duipai finished. (Too slow to code(write?) this, need more practice)

11:30

Drawing Poland Ball awa
Drawing Chinese ball is difficult..

-----


CSP-J only easy dp? strange

It means CSP-S have graph/SG/math??? so scare


----

?Well, maybe the files have some problems. They just like:

ZJ-J00xxx
    |------Download
    |------Desktop
    |------number
        |------number.cpp
    |------seat
        |------seat.cpp
    .....(other cpp)

    |------<Competitors must know.pdf>
    |------csp-j.zip



However, I don't sure if the pdf, the Download file or the zip will make a difference on my answer.(make a difference on? I'm not good at English)
The pdf said the file(ZJ-Jxxxxx) must only include 4 files(4 problems) but it has been include other files and they can't deleted(Such as Download).
I think they won't influence my answer.(Is it the right grammar? :D)

(Although I can type Chinese, it may make my program CE.

It's better not to do it qwq)




Birds --Imagine Dragon & Elisa (some words are empty ear--kong'er(I forgot words D;))

Two hearts One value
Living the dream, Watching the cream
Changing the season
Two lives One lie
Pupping the blood We are the flood
We can the diye(?)
Seasons will be change
Live will make you grow
Dreams will make it hard hard hard
Everything is temperary
Everything make it slide
Love will never die die die
I know that Ohh~
Birds fly in different directions
Ohh~
I hope to see you again

Sun sets Sun rises
Living the dream, Watching the cream
Changing the season
Sometimes
I think of you
** the past ** the drast(?)
** the demon(?all forget)
Seasons will be change
Live will make you grow
Dreams will make it hard hard hard
Everything is temperary
Everything make it slide
Love will never die die die
I know that Ohh~
Birds fly in different directions
Ohh~
I hope to see you again
Ohh~
Birds fly in different directions
Ohh~
It's fly high
It's fly high

When the moon is looking down
When she shadow starts to grown
I'm flying to let you see
That shadow caust(?) is me
I know that Ohh~
Birds fly in different directions
Ohh~
I hope to see you again
Ohh~
Birds fly in different directions
Ohh~
I hope to see you again
Ohh~
Birds fly in different directions
Ohh~
It's fly high
It's fly high









*/