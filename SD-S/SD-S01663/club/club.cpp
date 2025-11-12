#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=5e4+10;
int t,n,a[N][5],maxn[N],maxx[5][M],ans;
bool cmp(int x,int y){
	if (x>y){
		return 1;
	}
	else {
		return 0;
	}
}
void cp(int x){
	for (int i=1;i<=n;i++){
		maxn[i]=a[i][x];
	}
}
void qz(int l){
	memset(maxn,0,sizeof(maxn));
	for (int j=1;j<=3;j++){
		cp(j);
		sort(maxn+1,maxn+n+1,cmp);
		for (int i=1;i<=n;i++){
			maxx[j][i]=maxn[i];
		}
	}
	//¾Ùµ¥ÁÐ
	int dl=0;
	if (n!=2){
		for (int i=1;i<=3;i++){
			dl+=maxx[i][1];
		}
		int cnt=-1,sum,k=0;
	for (int j=1;j<=3;j++){
		sum=0;
		for (int i=1;i<=l;i++){
			sum+=maxx[j][i];	
		}
		if (sum>cnt){
			k=j;
			cnt=sum;
		}
	} 
	ans=cnt;
	if (k==1){
		ans+=maxx[2][1];
		ans+=maxx[3][1];
	}
	else if (k==2){
		ans+=maxx[1][1];
		ans+=maxx[3][1]; 
	}
	else{
		ans+=maxx[1][1];
		ans+=maxx[2][1]; 
	}
	cout<<max(ans,dl)<<endl;
	}
	else{
		cout<<max((maxx[1][1]+maxx[1][2]),(maxx[1][2]+maxx[2][1])<<endl;
	}
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
    	cin>>n;
    	ans=0;
    	for (int i=1;i<=n;i++){
    		for (int j=1;j<=3;j++){
    			cin>>a[i][j];
			}
		}
		qz(n/2);
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
}

