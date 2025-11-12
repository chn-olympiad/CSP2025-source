#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int T;
int n,ner;
//int cnt1=0,cnt2=0,cnt3=0;
int cntA[N]= {0};
int cntB[N]= {0};
int cntC[N]={0};
long long ans=0;

struct yg {
	int a,b,c;
} x[N];

//特判 是否超成员
bool spe(int p) {
	if(p>=ner) {
		return false;
	} else {
		return true;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
		ner=n/2;
		for(int i=1; i<=n; i++) {
			cin>>x[i].a>>x[i].b>>x[i].c;
		}
		//特殊性质 A
		for(int i=1; i<=n; i++) {
			if(x[i].b==0&&x[i].c==0) {
				cntA[i]=max(x[i].a,cntA[0]);
			}
		}
		sort(cntA+1,cntA+n+1);
		long long ansA=0;
		for(int i=n; i>=ner+1; i--) {
			ansA=ansA+cntA[i];
		}
		if(ansA>0){
			cout<<ansA<<'\n';
		}
		
		//特殊性质 B
		int jlA=0,jlB=0,ts=0;
		long long ansB=0;
		for(int i=1; i<=n; i++) {
			if(x[i].b!=0&&x[i].c==0) {
				cntB[i]=max(x[i].a,x[i].b);
				if(cntB[i]==x[i].a&&cntB[i]!=x[i].b) {
					jlA++;
					if(jlA>ner) {
                        ansB=ansB+x[i].b;
					}else{
						ansB=ansB+cntB[i];
					}
					
				}
				if(cntB[i]==x[i].b&&cntB[i]!=x[i].a) {
					jlB++;
					if(jlB>ner) {
                        ansB=ansB+x[i].a;
					}else{
						ansB=ansB+cntB[i];
					}
				}
				if(cntB[i]==x[i].a&&cntB[i]==x[i].a) {
					ts=min(jlA,jlB);
					if(ts==jlA&&ts!=jlB){
						jlA++;
					}else{
						jlB++;
					}
					ansB=ansB+cntB[i];
				}
			}
		}
		if(ansB>0){
			cout<<ansB<<'\n';
		}
		
		//正常
		int jA=0,jB=0,jC=0,tsd=0;
		long long ansC=0;
		for(int i=1; i<=n; i++) {
			
				cntC[i]=max(x[i].a,x[i].b);
				cntC[i]=max(x[i].c,cntC[i]);
				if(cntC[i]==x[i].a&&cntC[i]!=x[i].b&&cntC[i]!=x[i].c) {
					jA++;
					if(jA>ner) {
						if(jB>ner&&jC<=ner){
							ansC=ansC+x[i].c;
						}else{
							ansC=ansC+x[i].b;
						}
                        
					}else{
						ansC=ansC+cntC[i];
					}
					
				}
				if(cntC[i]==x[i].b&&cntC[i]!=x[i].a&&cntC[i]!=x[i].c) {
					jB++;
					if(jB>ner) {
                        if(jA>ner&&jC<=ner){
							ansC=ansC+x[i].c;
						}else{
							ansC=ansC+x[i].a;
						}
					}else{
						ansC=ansC+cntC[i];
					}
				}
				if(cntC[i]==x[i].a&&cntC[i]!=x[i].b&&cntC[i]!=x[i].c) {
					tsd=min(jA,jB);
					tsd=min(ts,jC);
					if(tsd==jA&&tsd!=jB&&tsd!=jC){
						jA++;
					}else{
						if(tsd==jB){
							jB++;
						}else{
							jC++;
						}
					}
					ansC=ansC+cntC[i];
				}
			
		}
		if(ansC>0){
			cout<<ansC<<'\n';
		}
		 
	}
	return 0;
}
