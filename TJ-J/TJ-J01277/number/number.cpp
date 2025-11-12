#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a;
int n[1000005],t;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin.tie(0);
	cout.tie(0); 
    cin >> a;
    for(int i=0;i<a.size();i++){
        if ((a[i]-'0'<=9)||(a[i]-'0'<=0)){
            n[t]=a[i]-'0';
            t++;
        }
    }
    sort(n,n+t);
    for(int i=t-1;i>=0;i--){
        cout << n[i];
    }
    fclose(stdin);
    fclose(stdout);
}
