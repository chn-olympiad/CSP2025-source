#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<int> a;
bool checka(){
    if(k!=0){
        return false;
    }
    for(int i=0;i<n;i++){
        if(a[i]!=1){
            return false;
        }
    }
    return true;
}
bool checkb(){
    if(k!=0&&k!=1){
        return false;
    }
    for(int i=0;i<n;i++){
        if(a[i]!=1&&a[i]!=0){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio;
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    //特殊情况A，k等于0，并且所有数都为1
    //那么最多的区间数目就是1两两组合，最后结果是n/2向下取整
    if(checka()){
        cout << n/2;
        return 0;
    }
    //特殊情况B，k=1或0，并且所有的数字都为0或1
    //如果k==1，那么最多的区间数目是1的个数(因为两个数字不一样才会==1，而字符串中只有0和1，所以每个等于1的xor区间必然包含一个1)
    //如果k==0，那么最多的区间数目是0的个数加上成对的1的对数
    if(checkb()){
        int cnt = 0;
        if(k==1){
            for(int i=0;i<n;i++){
                if(a[i]==1){
                    cnt++;
                }
            }
        }
        if(k==0){
            for(int i=0;i<n;){
                if(a[i]==0){
                    cnt++;
                    i++;
                }else if(a[i]==1&&a[i+1]==1&&i+2<n){
                    cnt++;
                    i+=2;
                }else{
                    i++;
                }
            }
        }
        cout << cnt;
        return 0;
    }
}