#include<bits/stdc++.h>
using namespace std;
int ta[100005],tb[100005],tc[100005];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,aa=0,bb=0,cc=0,ak=0,bk=0,ck=0;
		cin>>n;
		long long cnt=0;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			int x=max({a,b,c});
			if(a==x){
				aa++;
				ta[++ak]=a-max(b,c);
			}else if(b==x) {
				bb++;
				tb[++bk]=b-max(a,c);
			}
			else {
				cc++;
				tc[++ck]=c-max(a,b);
			}
			cnt+=x;
		}if(aa>n/2){
			sort(ta+1,ta+1+ak);
			for(int i=1;i<=aa-n/2;i++)cnt-=ta[i];
		}if(bb>n/2){
			sort(tb+1,tb+1+bk);
			for(int i=1;i<=bb-n/2;i++)cnt-=tb[i];
		}if(cc>n/2){
			sort(tc+1,tc+1+ck);
			for(int i=1;i<=cc-n/2;i++)cnt-=tc[i];
		}cout<<cnt<<'\n';
	}
	return 0;
}