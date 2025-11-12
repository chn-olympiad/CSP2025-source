#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int num1[N][22],b[N],sum_num[22],n,k,p,hplce=0,ans=0;
struct node{
	int a[22];
	bool friend operator <(const node x,const node y){
		for(int i=21;i>=1;i--){
			if(x.a[i]!=y.a[i]) return x.a[i]<y.a[i];
		}
		return 0;
	}
}v[N],sk;
node plus23(node x,node y){
	node z;
	for(int i=21;i>=1;i--){
		z.a[i]=(x.a[i]+y.a[i])%2;
	}
	return z;
}
void sayout(node x){
	for(int i=21;i>=1;i--){
		cout<<x.a[i];
	}
	cout<<" ";
}
map<node,int>mp;
vector<node>vec;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;k>0;i++){
		sum_num[i]=k&1;
		k>>=1;
		if(k==0) break;
	}
	for(int i=1;i<=n;i++){
		cin>>p;
		b[i]=p;
		for(int j=21;j>=1;j--){
			int yur=(p>>(j-1))&1;
			num1[i][j]=yur;
			//cout<<num1[i][j];
		}
		//cout<<"\n";
	}
	int nowchose=-2;
	mp[sk]=-1;
	for(int i=1;i<=n;i++){
		node xx,yy;
		for(int j=21;j>=1;j--){
			xx.a[j]=num1[i][j];
			//cout<<xx.a[j];
		}
		//cout<<"\n";
		for(int j=21;j>=1;j--){
			yy.a[j]=abs(xx.a[j]-sum_num[j]);
			//cout<<yy.a[j];
		}
		//cout<<"\n";
		if(mp[yy]!=0&&mp[yy]>nowchose){
			ans++;
			nowchose=i;
			//mp.clear();
			mp[sk]=nowchose+1;
			vec.clear();
		}
		else{
		
			for(auto x:vec){
				//sayout(plus23(x,xx));
				//cout<<mp[x]<<"\n";
				mp[plus23(x,xx)]=i;
			}
			vec.push_back(xx);
		}
			mp[xx]=i;
		//cout<<ans<<" "<<nowchose<<"\n";
	}
	cout<<ans;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 
