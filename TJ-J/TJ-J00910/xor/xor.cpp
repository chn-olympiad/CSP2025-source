
#include <bits/stdc++.h>
using namespace std;

const long long int N = 5e5;
int num[N],n,k;
int ans[N];

int myxor(int s,int e){
    int xsum = num[s];
    for(int i=s+1 ; i<=e ; i++){
        xsum = xsum^num[i];
    }
    return xsum;
}

void dfs(int l,int r,int t){
    if((l>r) || r>n) return;
    int xs = myxor(l,r);
    if(xs != k)dfs(l,r+1,t);
    else{
        ans[t]++;
        dfs(l+1,r+1,t);
    }

    dfs(l+1,r+1,t+1);
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin >> n >>  k;
    for(int i=1 ; i<=n ; i++){
        cin >> num[i];
    }

    dfs(1,1,1);

    int answer = -1;
    for(int i = 1 ; i<=n ; i++){
        cout << ans[i] << ' ';
        answer = max(answer,ans[i]);
    }

    cout << answer;

    fclose(stdin);
    fclose(stdout);

    return 0;
}

