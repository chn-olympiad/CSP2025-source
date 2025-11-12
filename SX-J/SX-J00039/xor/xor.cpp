#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s,x;
    cin >> n >> k;
    for (int i =1;i <= n;i++){
        cin >> x;
        if (x == k)
            s++;
	cout << s;
	return 0;
}