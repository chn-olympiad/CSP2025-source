#include<bits/stdc++.h>
using namespace std;

map<string,int> cnta;
map<string,int> cntb;
int n,q,top,a[200005],b[200005],ans;//cnta[1000005],cntb[1000005];
string s1[200005],s2[200005],x,y;
void cheak(string x,string y){
	if(x.length()!=y.length())return;
	int l=x.length();int w1=0,w2=0;top++;
	for(int i=0;i<=l-1;i++){
		if(x[i]!=y[i]){
			w1=i;
			break;
		}
	}
	for(int i=l-1;i>=0;i--){
		if(x[i]!=y[i]){
			w2=i;
			break;
		}
	}
	a[top]=w1;
	b[top]=w2;
}
void solve(string x,string y){
	if(x.length()!=y.length())return;
	int l=x.length();int w1=0,w2=0;top++;
	for(int i=0;i<=l-1;i++){
		if(x[i]!=y[i]){
			w1=i;
			break;
		}
	}
	for(int i=l-1;i>=0;i--){
		if(x[i]!=y[i]){
			w2=i;
			break;
		}
	}
//	cout<<w1<<" "<<w2<<endl;
	for(int i=1;i<=n;i++){
		if(a[i]==b[i]&&a[i]==0)continue;
		if(w2-w1+1==b[i]-a[i]+1&&x.length()>=s1[i].length()&&y.length()>=s2[i].length()){
//			cout<<i<<endl;
			int t=w1,r=a[i],flag=0;
			while(t<=w2){	
				if(x[t]==s1[i][r]&&y[t]==s2[i][r]){
	//				cout<<x[t]<<" "<<s1[i][r]<<" "<<y[t]<<" "<<s2[i][r]<<endl;
				}else{
					flag=1;
					break;
				}
				t++,r++;
			}
			if(flag==0)ans++;
		}
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		if(cnta[s1[i]]==0&&cntb[s2[i]]==0&&s1[i]!=s2[i]){
			cheak(s1[i],s2[i]);
		}else{
			a[++top]=0;
			b[top]=0;
		}
		cnta[s1[i]]++,cntb[s2[i]]++;
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" "<<b[i]<<endl;
//	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>x>>y;
		solve(x,y);
		cout<<ans<<endl;
	}
	return 0;
}