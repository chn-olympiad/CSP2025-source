#include <bits/stdc++.h>
using namespace std;
int t, n, a[500005][5], number[5];
int choose[500005];
long long ans=0, cnt=0;
bool check(){
    for(int i=1; i<=3; i++){
        if(number[i]>(n/2)) return 0;
    }
    return 1;
}
bool cmp(int a, int b){
	return a>b;
}
void dfs(int step){
    if(step>n){
        if(check()){
            ans = max(ans, cnt);
        }
        return;
    }
    for(int i=1; i<=3; i++){
        choose[step] = i;
        number[i] +=1;
        cnt += a[step][i];
        if(check()) dfs(step+1);
        cnt -= a[step][i];
        number[i] -=1;
    }
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--){
        ans = 0;
        cin >> n;
        bool is_a=1; 
        for(int i=1; i<=n; i++){
            scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
            if(a[i][2]!=0 || a[i][3]!=0) is_a = 0;	 
        }
        if(is_a){
        	int club[500005];
        	for(int i=1; i<=n; i++){
        		club[i] = a[i][1];
			}
			sort(club+1, club+1+n, cmp);
			for(int i=1; i<=(n/2); i++) ans+=club[i];
			cout << ans << endl;
			continue;
		}
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}
