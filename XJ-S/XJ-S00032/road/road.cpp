#include<bits/stdc++.h>
using namespace std;
int n,d,money;
string v,a;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdin);
    cin >> n;
    for(int i=1;i<n;i++){
		cin >> v[i];
	}
	for(int i=1;i<n;i++){
		cin >> a[i];
	}
	money=int(v[-1])*int(a[-1]);
    cout << money;
    fclose(stdin);
    fclose(stdout);
}
