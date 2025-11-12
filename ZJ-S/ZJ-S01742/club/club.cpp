#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T, N;

struct Student {
    ll a, b, c;
} arr[100005];

ll f[205][105][105];

void sol()
{
    memset(f, 0xcf, sizeof(f));
    f[0][0][0] = 0, f[1][1][0] = arr[1].a, f[1][0][1] = arr[1].b, f[1][0][0] = arr[1].c;
    ll ans = 0;
    for(int i = 2; i <= N; ++ i)
    {
        for(int cnt_a = 0; cnt_a <= i && cnt_a <= N / 2; ++ cnt_a)
        {
            for(int cnt_b = 0; cnt_b + cnt_a <= i && cnt_b <= N / 2; ++ cnt_b)
            {
                int cnt_c = i - cnt_a - cnt_b;
                if(cnt_c > N / 2) continue;
                if(cnt_a > 0) f[i][cnt_a][cnt_b] = max(f[i][cnt_a][cnt_b], f[i - 1][cnt_a - 1][cnt_b] + arr[i].a);
                if(cnt_b > 0) f[i][cnt_a][cnt_b] = max(f[i][cnt_a][cnt_b], f[i - 1][cnt_a][cnt_b - 1] + arr[i].b);
                if(cnt_c > 0) f[i][cnt_a][cnt_b] = max(f[i][cnt_a][cnt_b], f[i - 1][cnt_a][cnt_b] + arr[i].c);
                if(i == N)
                    ans = max(ans, f[i][cnt_a][cnt_b]);
            }
        }
    }
    
    cout << ans << endl;
}

bool cmp1(Student x, Student y)
{
	return x.a < y.a;
}

void solA()
{
	sort(arr + 1, arr + N + 1, cmp1);
	int sumA = 0;
	for(int i = N; i > N / 2; -- i)
		sumA += arr[i].a;
	
	cout << sumA << endl;
}

void solB()
{
	sort(arr + 1, arr + N + 1, cmp1);
	int sumA = 0;
	for(int i = N; i > N / 2; -- i)
		sumA += arr[i].a;
	
	for(int i = N / 2; i >= 1; -- i)
		sumA += arr[i].b;
		
	cout << sumA << endl;
}

signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while(T --)
    {
    	bool flagA, flagB;
    	flagA = flagB = true;
        cin >> N;
        for(int i = 1; i <= N; ++ i)
        {
            cin >> arr[i].a >> arr[i].b >> arr[i].c;
            if(arr[i].b != 0 || arr[i].c != 0) flagA = false;
            if(arr[i].c != 0) flagB = false;
    	}

        if(N <= 200) sol();
        else if(flagA) solA();
        else if(flagB) solB();
        else puts("I don't know how to solve this. :( ");
    }
    
    return 0;
}