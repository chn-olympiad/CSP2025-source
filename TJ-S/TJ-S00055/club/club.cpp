 #include <bits/stdc++.h>
using namespace std;
int t;
int n;
struct que{
	int val,num;
	int friend operator < (que x,que y){
		return x.val < y.val;
	}
};
int a[500050][3],dp[500050],wh[500050],w[5];
priority_queue <que> q[5];
void thr(){
	que q1,q2,q3;
	if(!q[1].empty()){
		q1 = q[1].top();
	}else{
		q1.num = 0;
		q1.val = 0;
	}
	if(!q[2].empty()){
		q2 = q[2].top();
	}else{
		q2.num = 0;
		q2.val = 0;
	}
	if(!q[3].empty()){
		q3 = q[3].top();
	}else{
		q3.num = 0;
		q3.val = 0;
	}
	while(wh[q1.num] != 0 and !q[1].empty()){
		q[1].pop();
		q1 = q[1].top();
	}
	while(wh[q2.num] != 0 and !q[2].empty()){
		q[2].pop();
		q2 = q[2].top();
	}
	while(wh[q3.num] != 0 and !q[3].empty()){
		q[3].pop();
		q3 = q[3].top();
	}
	return;
}
void thm(){
	que q1,q2,q3;
	if(!q[1].empty()){
		q1 = q[1].top();
	}else{
		q1.num = 0;
		q1.val = 0;
	}
	if(!q[2].empty()){
		q2 = q[2].top();
	}else{
		q2.num = 0;
		q2.val = 0;
	}
	if(!q[3].empty()){
		q3 = q[3].top();
	}else{
		q3.num = 0;
		q3.val = 0;
	}
	if(q1.val >= max(q2.val,q3.val)){
		wh[q1.num] = 1;
		w[1]++; 
		q[1].pop();
	}else if(q2.val >= max(q1.val,q3.val)){
		wh[q2.num] = 2;
		w[2]++; 
		q[2].pop();
	}else{
		wh[q3.num] = 3;
		w[3]++; 
		q[3].pop();
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		memset(wh,0,sizeof(wh));
		memset(w,0,sizeof(w));
		cin>>n; 
		for(int i = 1;i<=n;i++){
			que k;
			k.num = i;
			for(int j = 1;j<=3;j++){
				cin>>k.val;
				q[j].push(k);
			}
		}
		que q1,q2,q3;
		q1 = q[1].top();
		q2 = q[2].top();
		q3 = q[3].top();
		dp[1] = max(q1.val,max(q2.val,q3.val));
		thm();
		for(int i = 2;i<=n;i++){//容量 
			thr();
			//扔掉用过的 
			if(!q[1].empty()){
				q1 = q[1].top();
			}else{
				q1.num = 0;
				q1.val = 0;
			}
			if(!q[2].empty()){
				q2 = q[2].top();
			}else{
				q2.num = 0;
				q2.val = 0;
			}
			if(!q[3].empty()){
				q3 = q[3].top();
			}else{
				q3.num = 0;
				q3.val = 0;
			}
			dp[i] = dp[i-1] + max(q1.val,max(q2.val,q3.val));
			thm();
			thr();
			//是拿一个新的更好还是踢掉一个换新的更好 踢掉j 
			for(int j = 1;j<=n;j++){
				if(wh[j] != 0){
					int cnt = 0;
					int sum = 0;
					for(int k = 1;k<=3;k++){
						if(k != j  and w[k] < n/2){
							if(cnt < a[j][k]) sum = k;
							cnt = max(cnt,a[j][k]);
						}
					}
					que qu = q[wh[j]].top();
					if(dp[i] < dp[i-1] - a[j][wh[j]] +  a[j][sum] + qu.val){
						dp[i] = dp[i-1] - a[j][wh[j]] +  a[j][sum] + qu.val;
						q[wh[j]].pop();
						wh[qu.num] = wh[j];
						w[wh[qu.num]]++;
						wh[j] = sum;
					}
					thr();
				}
				
			}
			
		}
		//for(int i = 1;i<=n;i++) cout<<dp[i]<<' ';
		cout<<dp[n]<<endl;
	}
	return 0;
}
