//T3
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
const int MAXN = 2e5;
const int NONE = 5e5;
string ss2[MAXN][2];
int B = -1,ans = 0,n,q;
bool canb = 1;

int isB(string t1,string t2){
    if(!canb) return NONE;
    int pret1b = 0,pret2b = 0;
    for(int i=0;i<t1.length();i++){
        if(t1[i]!='a'&&t1[i]!='b') return NONE;
        if(t2[i]!='a'&&t2[i]!='b') return NONE;
        if(t1[i]=='b'){
            if(pret1b) return NONE;
            pret1b = i;
        }
        if(t2[i]=='b'){
            if(pret2b) return NONE;
            pret2b = i;
        }
    }
    return pret2b-pret1b;
}

bool fc(string s,char c){
    int a = s.find(c);
    return a>=0&&a<s.length();
}

void preB(){
    for(int i=0;i<n;i++){
        for(char c='c';c<='z';c++){
            if(fc(ss2[i][0],c)||fc(ss2[i][1],c)){
                canb = 0;
                return;
            }
        }
        if(!fc(ss2[i][0],'a')||!fc(ss2[i][0],'b')||!fc(ss2[i][1],'a')||!fc(ss2[i][1],'b')){
            canb = 0;
            return;
        }
        for(int r=ss2[i][0].find('b')+1;r<ss2[i][0].length();r++){
            if(ss2[i][0][r]=='b'){
                canb = 0;
                return;
            }
        }
        for(int r=ss2[i][1].find('b')+1;r<ss2[i][1].length();r++){
            if(ss2[i][1][r]=='b'){
                canb = 0;
                return;
            }
        }
    }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=0;i<n;i++){
        cin >> ss2[i][0] >> ss2[i][1];
	}
	preB();
	for(int i=0;i<q;i++){//if one t1,t2 fullB,the node fullB;
        string t1,t2;ans = 0;
        cin >> t1 >> t2;
        if(t1.length()!=t2.length()){
            cout << "0\n";
            continue;
        }
        B = isB(t1,t2);
        if(B!=NONE&&canb){//25score at most
            for(int j=0;j<n;j++){
                ans += !(ss2[j][1].find('b') - ss2[j][0].find('b') - B);
            }
            cout << ans << "\n";
            continue;
        }
        //cout << "P" << canb << endl;
        //cout << ans << endl;
        for(int j=0;j<n;j++){//for each couple
            string s1 = ss2[j][0],s2 = ss2[j][1];
            //cout << s1 << " " << s2 << endl;
            for(int k=0;k+s1.length()<=t1.length();k++){
                bool same = 0,diffr = 1;
                if(t1[k]==s1[0]&&t2[k]==s2[0]){
                    same = 1;
                    for(int r=1;r<s1.length();r++){
                        if(s1[r]!=t1[k+r]){
                            same = 0;
                            break;
                        }
                        if(s2[r]!=t2[k+r]){
                            same = 0;
                            break;
                        }
                    }
                    if(same){
                        //cout << s1 << endl;
                        diffr = 0;
                        //cout << "k" << k << "s1len" << s1.length() << "t1len" << t1.length() << endl;
                        for(int r=k+s1.length();r<t1.length();r++){
                            //cout << "r" << r << endl;
                            if(t1[r]!=t2[r]){
                                diffr = 1;
                                break;
                            }
                        }
                        if(!diffr){
                            ans++;
                            break;
                        }
                    }
                }
                if(same&&!diffr) break;
                if(t1[k]!=t2[k]) break;
            }
        }
        cout << ans << "\n";
	}

	return 0;
}
