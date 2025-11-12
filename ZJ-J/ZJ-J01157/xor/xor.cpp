#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,k,a[N],slv1[1010][1010],anslen,num,cnt,maxx;
map<int,int>mp;
struct pos{
	int x,y,cha;
}ans[N];
bool cmp(pos X,pos Y){
	return X.cha<Y.cha;
}
void slvb(){
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]&&k==0){
			num++;
			i++;
		}
		else if(a[i]!=a[i-1]&&k==1){
			num++;
			i++;
		}
	}
	cout<<num;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(k<=1&&maxx==1){
		slvb();
		return 0;
	}
	for(int i=1;i<=n;i++){
		int res=a[i];
		slv1[i][i]=a[i];
		for(int j=i+1;j<=n;j++){
			res^=a[j];
			slv1[i][j]=res;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(slv1[i][j]==k){
				cnt++;
				if(!mp[i]) mp[i]=j;
				else mp[i]=min(mp[i],j);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(mp[i]){
			ans[++anslen]=(pos){i,mp[i],mp[i]-i};
			mp[i]=0;
		}
	}
	sort(ans+1,ans+anslen+1,cmp);
	for(int i=1;i<=anslen;i++){
		int flag=1;
		for(int j=ans[i].x;j<=ans[i].y;j++){
			if(mp[j]){
				flag=0;
				break;
			}
		}
		if(!flag) continue;
		for(int j=ans[i].x;j<=ans[i].y;j++){
			mp[j]=1;
		}
		num++;
	}
	cout<<num;
	return 0;
}
