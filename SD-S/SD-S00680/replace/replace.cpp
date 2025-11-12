#include<bits/stdc++.h>
#define ll long long
#define lll __int128
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
#define ull unsigned long long
using namespace std;
const int N=1e6+145,P1=131,P2=13331;

ull ths1,ths2,p1[N],p2[N],qz1[N],qz2[N];
int n,q,l,r;
string s1,s2;
string q1,q2;
map<pair<ull,ull>,int> M;

void gths(int L,int R){
    ths1=qz1[R]-qz1[L-1]*p1[R-L+1];
    ths2=qz2[R]-qz2[L-1]*p2[R-L+1];
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    p1[0]=p2[0]=1;
    for(int i=1;i<=1000000;i++){
    	p1[i]=p1[i-1]*P1;
    	p2[i]=p2[i-1]*P2;
	}
    
    for(int i=1;i<=n;i++){
    	cin>>s1>>s2;
    	int len=s1.size();
    	ull hs1=0,hs2=0;
    	for(int j=0;j<len;j++)
    	    hs1=hs1*P1+s1[j]-'a'+1,
    	    hs2=hs2*P2+s2[j]-'a'+1;
    //	cout<<hs1<<" "<<hs2<<"\n";
    	++M[mp(hs1,hs2)];
	}
	for(int i=1;i<=q;i++){
		cin>>q1>>q2;
	    int len=q1.size();
	    
	    for(int j=0;j<len;j++)
	        qz1[j+1]=qz1[j]*P1+q1[j]-'a'+1,
	        qz2[j+1]=qz2[j]*P2+q2[j]-'a'+1;
	    for(int j=0;j<len;j++)
	        if(q1[j]!=q2[j]) {l=j;break;}
	    for(int j=len-1;j>=0;j--) 
		    if(q1[j]!=q2[j]) {r=j;break;}
		
	//	cout<<l<<" "<<r<<"\n";
		
		int ans=0;
		for(int be=0;be<=l;be++)
		    for(int ed=r;ed<len;ed++){
		    	gths(be+1,ed+1);
	//	    	cout<<ths1<<" "<<ths2<<"\n";
		    	pair<ull,ull> tmp=mp(ths1,ths2);
		    	if(M.find(tmp)!=M.end()) ans+=M[tmp];
			}
		printf("%d\n",ans);
	}
	return 0;
}

