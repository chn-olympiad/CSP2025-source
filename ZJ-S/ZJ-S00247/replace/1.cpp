#include<bits/stdc++.h>
using namespace std;
vector<int> a[5000005];
mt19937 rd(random_device{}());
int main(){
    for(int i=1;i<=5000000;i++) a[rd()%5000000+1].push_back(i);
}