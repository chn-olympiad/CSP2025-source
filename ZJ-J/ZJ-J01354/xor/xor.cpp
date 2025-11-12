#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n , k;

vector<int> num;

void tp(){
    return ;
}

signed main() {

	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

    cin  >> n >> k;

    int res = 0;

    for(int i = 1; i <= n ; i++){
        int x = 0;
        cin >> x;
        if(x == k){
            res ++;
            num.size() ? num.clear() : tp();
        }else{
            num.push_back(x);
        }
        if(!num.empty())
            for(int j = 0 ; j < num.size() - 1 ; j++)
            {
                if ((num[j] ^ x) == k){
                    res ++; 
                    num.clear();
                   break;
                }else{
                    num[j] ^= x;
              }
            }
    }

    cout << res << endl;

	return 0;
}
