#include <bits/stdc++.h>
using namespace std;
int n,m;
int vs;
int Maxn;
long long ans;
vector<int>  v;
bool vis=true;
long long bou_d(int b,int x,int p){
	long long ans=1;
	long long v=x;
	while(b>0){
		if(b%2==1){
			ans=ans*v;
			ans%=p;
		}
		b/=2;
		v=v*v;
		v%=p;
	}
	return ans;
}
void dfs(int id, int step, int sum){
//	cout << id+1 << " " << step << " "<<sum  << endl;
	if(step==vs-1&&sum<=Maxn){
		vis=false;
		return ;
	}
	
	if(sum>Maxn){
		ans+=bou_d(vs-2-id,2,998*244*353);
		ans%=998*244*353;
//		cout << id+1 << " " << step << " "<<sum  << endl;
//		cout << ans << endl;
		return ;
	}
	
	if(id==vs-2){
		if(sum<=Maxn) return ;
	}
	
	for(int j=id+1;j<vs-1&&vis;++j){
//		cout<< j << endl;
		dfs(j,step+1,sum+v[j]);
		
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> m;
		v.push_back(m);
	}
	sort(v.begin(),v.end());
	if(v[v.size()-1]==1){
		for(int i=3;i<=n;i++){
			long long a=1;
			for(int j=n;j>n-i;j--){
				a*=j;
				a%=998*244*353;
			}
			for(int j=i;j>=1;j--){
				a/=j;
				a%=998*244*353;
			}
			ans+=a;
			ans%=998*244*353;
		}
	}
	else{
		while(v.size()>=3){
			vs=v.size();
			Maxn=v[vs-1];
			for(int i=0;i<vs-1;++i){
				dfs(i,1,v[i]);
				
			}
			vis=true;
			v.pop_back();
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
