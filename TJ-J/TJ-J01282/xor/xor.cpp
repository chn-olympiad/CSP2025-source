#include<bits/stdc++.h>
using namespace std;
const int mxn=5e5+5;
struct st{
	int x,y;
}t[mxn];
int n,k,a[mxn];
int s[mxn];
long long cnt,ans;
bool cmp(st i,st j){
	if (i.y==j.y) return i.x<j.x;
	return i.y<j.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag=false;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]>1) flag=true;
	}
	if (flag==true){
		s[1]=a[1];
		for(int i=2;i<=n;i++) s[i]=a[i]^s[i-1];
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if ((s[j]^s[i-1])==k){
					cnt++;
					t[cnt].x=i;
					t[cnt].y=j;
				}
			}
		}
		sort(t+1,t+cnt+1,cmp);
		ans=1;
		int l=1;
		for(int i=2;i<=cnt;i++){
			if (t[i].x>t[l].y){
				ans++;
				l=i;
			}
		}
		cout<<ans;
	}else{
		int p=0,q=0;
		for(int i=1;i<=n;i++){
			if (a[i]==0) p++;
			else q++;
		}
		if (k==0) cout<<p;
		else cout<<q;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
