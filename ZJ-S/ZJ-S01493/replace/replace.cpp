#include <bits/stdc++.h>
using namespace std;
#define Pi pair<string,string>
const int N=5000010;
int n,m,lh,k,l,S,ans[200010];
struct pp{
	int x,y;
}a[200010],b[200010]; 
string A;
int f[N][26],L[N],R[N];
vector<int> p[500010];
map<pair<string,string>,vector<int> > m1,m2;
int add(){
	int x=0;
	for(int i=0;i<l;i++){
		int y=f[x][A[i]-'a'];
		if(y) x=y;
		else{
			f[x][A[i]-'a']=++S;
			x=S;
		}
	}
	return x;
}
int ask(){
	int x=0;
	for(int i=0;i<l;i++){
		int y=f[x][A[i]-'a'];
		if(y) x=y;
		else return S+1;
	}
	return x;
}
void solve(int x){
	L[x]=++S;
	for(int i=0;i<26;i++)
		if(f[x][i]) solve(f[x][i]);
	R[x]=S; 
}
struct PP{
	int x,l,r,t;
}st;
bool cmp2(PP a1,PP a2){
	if(a1.x==a2.x) return (!a1.t)<(!a2.t);
	return a1.x<a2.x;
}
int c[N];
void Add(int x){for(;x<=S;x+=x&-x) c[x]++;}
void del(int x){for(;x<=S;x+=x&-x) c[x]--;}
int ask(int x){
	int s1=0;
	for(;x;x-=x&-x) s1+=c[x];
	return s1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		k=x.length();
		int L=0,R=-1;
		A="";
		for(int i=0;i<k;i++){
			if(x[i]!=y[i]){
				L=i;
				break;
			}
			A.push_back(x[i]);
		}
		l=A.length();
		for(int i=0;i<l/2;i++) swap(A[i],A[l-i-1]);
		a[i].x=add();
		A="";
		for(int i=k-1;i>=0;i--){
			if(x[i]!=y[i]){
				R=i;
				break;
			}
			A.push_back(x[i]);
		}
		l=A.length();
		for(int i=0;i<l/2;i++) swap(A[i],A[l-i-1]);
		a[i].y=add();
		string X="",Y="";
		for(int i=L;i<=R;i++){
			X+=x[i];
			Y+=y[i];
		}
		m1[make_pair(X,Y)].push_back(i);
	}
	S=0;
	solve(0);
	for(int i=1;i<=m;i++){
		string x,y;
		cin>>x>>y;
		k=x.length();
		int L1=0,R=-1;
		A="";
		for(int i=0;i<k;i++){
			if(x[i]!=y[i]){
				L1=i;
				break;
			}
			A.push_back(x[i]);
		}
		l=A.length();
		for(int i=0;i<l/2;i++) swap(A[i],A[l-i-1]);
		b[i].x=L[ask()];
		A="";
		for(int i=k-1;i>=0;i--){
			if(x[i]!=y[i]){
				R=i;
				break;
			}
			A.push_back(x[i]);
		}
		l=A.length();
		for(int i=0;i<l/2;i++) swap(A[i],A[l-i-1]);
		b[i].y=L[ask()];
		string X="",Y="";
		for(int i=L1;i<=R;i++){
			X+=x[i];
			Y+=y[i];
		}
		m2[make_pair(X,Y)].push_back(i);
	}
	/*for(int i=1;i<=n;i++){
		cout<<L[a[i].x]<<" "<<R[a[i].x]<<" ";
		cout<<L[a[i].y]<<" "<<R[a[i].y]<<"\n";
	}*/
	/*for(int i=1;i<=m;i++)
		cout<<b[i].x<<" "<<b[i].y<<"\n";*/
	for(auto x:m2){
		vector<int> Lx=m1[x.first],Rs=x.second;
		vector<PP> rd;
		for(auto x:Lx){
//			cout<<x<<" "<<a[x].x<<"\n";
			st.x=L[a[x].x],st.t=1;
			st.l=L[a[x].y],st.r=R[a[x].y];
			rd.push_back(st);
			st.x=R[a[x].x]+1,st.t=-1;
			st.l=L[a[x].y],st.r=R[a[x].y];
			rd.push_back(st);
		}
		for(auto x:Rs){
			st.x=b[x].x,st.t=0;
			st.l=b[x].y,st.r=x;
			rd.push_back(st);
		}
		sort(rd.begin(),rd.end(),cmp2);
		for(auto x:rd){
		//	cout<<x.t<<" "<<x.x<<" "<<x.l<<" "<<x.r<<"\n";
			if(!x.t) ans[x.r]=ask(x.l);
			else if(x.t==1){
				Add(x.l);
				del(x.r+1);
			}else{
				del(x.l);
				Add(x.r+1);
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<"\n";
 return 0;
}
/*
代码可能来不及！！！我最终到底四题总共几分
我不能 //freopen 
*/
