#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'


using namespace std;
using LL = long long;

const int N1 = 1e4+5, N2 = 1e6+5;

int n, m, k, numm = 1;
int head[N1];

struct  point
{
    int dian;
    int quanzhi;
    int next;
} bian[N2];


void add(int x, int y, int z){
    //
    int t = head[x];
    bian[numm].dian = y;
    bian[numm].quanzhi = z;
    bian[numm].next = t;
    head[x] = numm;
    numm ++;
}

// priority_queue
int main(){

    IOS
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    
    cin >> n >> m >> k;
    LL sum = 0;
	for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            int u, v, w;
            cin >> u >> v >> w;
            add(u, v, w);
            add(v, u, w);
			sum += w;
        }
    }
    for(int i = 1; i <= k; i ++){
    	int x;
    	cin >> x;
    	for(int j = 1; j <= n; j ++){
    		cin >> x;
		}
	} 
    cout << sum << endl;
    
    return 0;
}
