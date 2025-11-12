#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e5+10;
i64 t;
i64 n;
i64 ans = 0;
i64 MaxTotal;
struct AD{
	i64 A;
	i64 B;
	i64 C;
}Arr[N];
void dfs(i64 now,i64 sum,i64 ATotal,i64 BTotal,i64 CTotal){
	//cout<<now<<endl;
	//cout<<ATotal<<" "<<BTotal<<" "<<CTotal<<endl;
	if(now>=n){
		if(ATotal<MaxTotal) ans = max(ans,sum+Arr[now].A);
		if(BTotal<MaxTotal) ans = max(ans,sum+Arr[now].B);
		if(CTotal<MaxTotal) ans = max(ans,sum+Arr[now].C);
		return ;
	}
	if(ATotal<MaxTotal) dfs(now+1,sum+Arr[now].A,ATotal+1,BTotal,CTotal);
	if(BTotal<MaxTotal) dfs(now+1,sum+Arr[now].B,ATotal,BTotal+1,CTotal);
	if(CTotal<MaxTotal) dfs(now+1,sum+Arr[now].C,ATotal,BTotal,CTotal+1);
	return ;
}
bool cmp(AD a,AD b){
	return a.A>b.A;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> t;
	while(t--){
		cin >> n;
		MaxTotal = n / 2;
		bool Aflag = true;
		//cout<<MaxTotal<<endl;
		ans = 0;
		for(int i=1;i<=n;i++){
			cin >> Arr[i].A >> Arr[i].B >> Arr[i].C;
			if(Arr[i].B!=0 || Arr[i].C!=0){
				Aflag=false;
			}
		}
		if(Aflag){
			sort(Arr+1,Arr+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans += Arr[i].A;
			}
		}
		else{
			dfs(1,0,0,0,0);
		}
		cout << ans << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}