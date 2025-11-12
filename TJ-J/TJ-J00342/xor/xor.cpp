#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001] = {},cnt = 0,res = 0,j;//,b[500001] = {};
bool all1 = 1,all0 = 1,first = 1;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] != 1)all1 = false;
        if(a[i] != 0)all0 = false;
        //b[i] = (b[i-1]^a[i]);
    }

    if(all1){
        if(k == 0)cout << n/2;
        else if(k == 1)cout << n;
        else cout << 0;
        return 0;
    }
    else if(all0){
        if(k == 0)cout << n;
        else cout << 0;
        return 0;
    }

    for(int i = 1;i <= n;i++){
        res = 0;
        first = true;
        while(i < n && a[i] == 0)i++;
        for(int j = i;j <= n;j++){
            while(first && j<n && a[j] == 0)j++;
            res ^= a[j];
            first = false;
            if(res == k){
                cnt++;
                j++;
                i = j;
            }
        }
    }
    cout << cnt;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
