#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000001] = {},cnt = 0,maxx = 0,a[1000001] = {},n;

void dfs(int d){
    if(d > cnt){
        n = 0;
        for(int i = 1;i <= cnt;i++){
            n = n*10+a[i];
        }
        if(maxx<n)maxx = n;
        return;
    }
    for(int i = d;i <= cnt;i++){
        a[d] = num[i];
        dfs(d+1);
    }
}

bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 0;i < s.size();i++){
        if(s[i] >= '0' && s[i] <= '9'){
            int tmp = s[i]-48;
            num[cnt+1] = tmp;
            cnt++;
        }
    }
    /*for(int i = 0;i < cnt;i++){
        for(int j = i;j < cnt;j++){
            if(num[i]<num[j])swap(num[i],num[j]);
        }
    }*/
    sort(num+1,num+cnt+1,cmp);
    dfs(1);
    cout << maxx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
