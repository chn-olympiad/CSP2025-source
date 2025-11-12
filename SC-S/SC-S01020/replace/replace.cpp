#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,q;
int trans1[N][26],trans2[N][26];
int tag1[N],tag2[N],len1[N],len2[N];
int cnt_node1=0,cnt_node2=0;
char s1[N],s2[N];
void add1(int x,char *p,int idx,int len){
	//cout << x << ' ' << (*p) << endl;
	if ((*p)==0){
		tag1[x]=idx;
		len1[x]=len;
		//cout << x << endl;
		return;
	}
	if (!trans1[x][(*p)-'a']){
		trans1[x][(*p)-'a']=++cnt_node1;
	}
	add1(trans1[x][(*p)-'a'],p+1,idx,len);
}
void add2(int x,char *p,int idx,int len){
	//cout << x << ' ' << (*p) << endl;
	if ((*p)==0){
		tag2[x]=idx;
		len2[x]=len;
		return;
	}
	if (!trans2[x][(*p)-'a']){
		trans2[x][(*p)-'a']=++cnt_node2;
	}
	add2(trans2[x][(*p)-'a'],p+1,idx,len);
}
queue <int> q1,q2;
int f1[N],f2[N];
void bfs1(){
	f1[0]=0;
	for (int i=0;i<26;i++){
		if (trans1[0][i]) q1.push(trans1[0][i]);
	}
	while(!q1.empty()){
		
		int x=q1.front();q1.pop();
		//cout << x << endl;
		for (int i=0;i<26;i++){
			int to=trans1[x][i];
			//cout << to << ' ';
			if (to){
				q1.push(to);
				f1[to]=trans1[f1[x]][i];
			}
			else{
				trans1[x][i]=trans1[f1[x]][i];
			}
		}
		//cout << endl;
	}
}
void bfs2(){
	f2[0]=0;
	for (int i=0;i<26;i++){
		if (trans2[0][i]) q2.push(trans2[0][i]);
	}
	while(!q2.empty()){
		int x=q2.front();q2.pop();
		for (int i=0;i<26;i++){
			int to=trans2[x][i];
			if (to){
				q2.push(to);
				f2[to]=trans2[f2[x]][i];
			}
			else{
				trans2[x][i]=trans2[f2[x]][i];
			}
		}
	}
}
int dp[N];
int ans=0;
bool vis[N];
void solve(int x1,int x2,char *p1,char *p2,int cntl){
	//cout << x1 << ' ' << x2 << ' ' << cntl << endl;
	
	int t1=x1,t2=x2;
	if (tag1[t1]==tag2[t2]&&tag1[t1]&&!vis[t1]){
		vis[t1]=1;
		ans++;
		dp[cntl]+=dp[cntl-len1[t1]];
		//cout << cntl << ' ' << len1[t1] << endl;
	}
	while(f1[t1]){
		t1=f1[t1],t2=f2[t2];
		//cout << t1 << ' ' << t2 << ' ' << tag1[t1] << ' ' << tag2[t2] << endl; 
		if (tag1[t1]==tag2[t2]&&tag1[t1]&&!vis[t1]){
			vis[t1]=1;
			ans++;
			dp[cntl]+=dp[cntl-len1[t1]];
			//cout << cntl << ' ' << len1[t1] << endl;
		}
	}
	if ((*p1)==0||(*p2)==0){
		return;
	}
	if ((*p1)==(*p2)) dp[cntl+1]+=dp[cntl];
	//cout << cntl << ' ' << dp[cntl] << endl;
	solve(trans1[x1][(*p1)-'a'],trans2[x2][(*p2)-'a'],p1+1,p2+1,cntl+1);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin >> n >> q;
    for (int i=1;i<=n;i++){
    	cin >> s1 >> s2;
    	add1(0,s1,i,strlen(s1));
    	add2(0,s2,i,strlen(s1));
	}
    bfs1();bfs2();
//    for (int i=0;i<=cnt_node1;i++){
//    	cout << f2[i] << ' ';
//	}
//	cout << endl;
    while(q--){
    	cin >> s1 >> s2;
    	if (strlen(s1)!=strlen(s2)){
    		cout << 0 << endl;
    		continue;
		}
		for (int i=1;i<=strlen(s2);i++){
			dp[i]=0;
		}
    	ans=0;
    	dp[0]=1;
    	solve(0,0,s1,s2,0);
    	cout << dp[strlen(s1)] << endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
