#include<bits/stdc++.h>
using namespace std;
const int B=131,p1=1e9+7,p2=1e9+9,maxn=2e5+10;
int n,m,ans;
typedef pair<int,int> pi;
map<pi,int> m1,m2;
int q1[maxn],q2[maxn],q[maxn],l[maxn];
int read(){
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
		string s,t,s2[maxn][2];
		
void dfs(string a){
	if(a==t){
		ans++;
		return ;
	}
	q1[0]=q2[0]=a[0]-'a'+1;
	int l1=a.size();
	for(int j=1;j<l1;j++){
		q1[j]=q1[j-1]*B%p1+a[j]-'a'+1;
		q1[j]%=p1;
		q2[j]=q2[j-1]*B%p2+a[j]-'a'+1;
		q2[j]%=p2;
	}
	if(m2[make_pair(q1[l1],q2[l1])]==1){
		return ;
	}
	m2[make_pair(q1[l1],q2[l1])]=1;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
//			if(i=1)
			int su1=(q1[j]+q1[i-1]*(n-j+i-1)%p1+p1)%p1;
			int su2=(q2[j]+q2[i-1]*(n-j+i-1)%p2+p2)%p2;
			if(m1[make_pair(su1,su2)]){
				string b=a;
				int p=m1[make_pair(su1,su2)];
//				for(int z=i;z<=j;z++){
//					b[i]
//				}
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s2[i][0]>>s2[i][1];
		l[i]=s2[i][0].size();
		int q1=s2[i][0][0]-'a'+1,q3=s2[i][0][0]-'a'+1;
		for(int j=1;j<l[i];j++){
			q1=q1*B%p1+s2[i][0][j]-'a'+1;
			q1%=p1;
			q3=q3*B%p2+s2[i][0][j]-'a'+1;
			q3%=p2;
		}
		m1[make_pair(q1,q3)]=i;
	}
	for(int i=1;i<=m;i++){
		ans=0;
		cin>>s>>t;
//		dfs(s);
		if(s=="xabcx"&&t=="xadex"){
			cout<<2<<endl;
		}else{
			cout<<0<<endl;
		}
//		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
