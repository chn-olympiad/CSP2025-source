#include <bits/stdc++.h>
using namespace std;

const int MAXN=5010;
int n,p[MAXN],side=3,maxverstappenside;
long long sum;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> p[i];
        sum += p[i];
        //DU DU DU DU MAX VERSTAPPEN
        maxverstappenside = max(maxverstappenside,p[i]);
    }
    if(sum > 2* maxverstappenside)cout <<1;
    else cout << 0;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
