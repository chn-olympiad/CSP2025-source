#include<bits/stdc++.h>

using namespace std;
string ans;
string s[500005];
long long x,anss;
long long maxx,n,k,slen[500005];
struct node{
	long long l,r;
}ns[500005];
string chuli(long long x){
	string h;
	if(x==0){
		h+="0";
		return h;
	}
	while(x!=0){
		if(x%2==1){
			h+="1";
		}
		else{
			h+="0";
		}
		x/=2;
	}
	return h;
}
string y;
long long qujian(long long x,long long i){
	x++;
	if(i>n){
		return 0x3f3f3f3f;
	}
	if(x==1){
		if(s[i]==ans){
			return i;
		}
	}
	else{
		for(long long j=0;j<maxx;j++){
			if(y[j]==s[i][j]){
				y[j]='0';
			}
			else{
				y[j]='1';
			}
		}
	}
	//cout<<x<<" "<<y<<endl;
	if(y==ans){
		return i;
	}
	else{
		qujian(x+1,i+1);
	}
}
bool cmp(node x,node y){
	if(x.r==y.r){
		return x.l>y.l;
	}
	else{
		return x.r>y.r;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	ans=chuli(k);
	long long anslen=ans.size();
	maxx=max(anslen,maxx);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&x);
		s[i]=chuli(x);
		slen[i]=s[i].size();
		maxx=max(slen[i],maxx);
	}
	if(maxx>anslen){
		for(long long i=1;i<=maxx-anslen;i++){
			ans+="0";
		}
		
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=maxx-slen[i];j++){
			s[i]+="0";
		}
		
	}
	for(long long i=1;i<=n;i++){
		y=s[i];
		ns[i].l=i;
		ns[i].r=qujian(0,i);
	}
	sort(ns+1,ns+n+1,cmp);
	/*for(int i=1;i<=n;i++){
		cout<<ns[i].l<<" "<<ns[i].r<<endl;
	}*/
	long long minn=0x3f3f3f3f3f;
	for(long long i=1;i<=n;i++){
		if(ns[i].l<minn&&ns[i].r<minn&&ns[i].r!=0x3f3f3f3f){
			anss++;
			minn=ns[i].l;
		}
	}
	cout<<anss;
	return 0;
}
