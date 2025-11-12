#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int t,n,a[100010][7]={0},ans=0;
vector<int>c[3];

int getFirstClub(int i){
    if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
        return 1;
    }else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
        return 2;
    }else if(a[i][3]>=a[i][1] && a[i][3]>=a[i][2]){
        return 3;
    }
}

int getSecondClub(int i){
    if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
        if(a[i][2]>=a[i][3]){
            return 2;
        }else{
            return 3;
        }
    }else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
        if(a[i][1]>=a[i][3]){
            return 1;
        }else{
            return 3;
        }
    }else if(a[i][3]>=a[i][1] && a[i][3]>=a[i][2]){
        if(a[i][1]>=a[i][2]){
            return 1;
        }else{
            return 2;
        }
    }
}

int getThirdClub(int i){
    if(a[i][1]<=a[i][2] && a[i][1]<=a[i][3]){
        return 1;
    }else if(a[i][2]<=a[i][1] && a[i][2]<=a[i][3]){
        return 2;
    }else if(a[i][3]<=a[i][1] && a[i][3]<=a[i][2]){
        return 3;
    }
}

bool cmp(int ia,int ib){
    return a[ia][a[ia][4]]-a[ia][a[ia][5]]>a[ib][a[ib][4]]-a[ib][a[ib][5]];
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(false);

    cin>>t;
    for(int times=1;times<=t;times++){
        ans=0;
        c[1].clear();
        c[2].clear();
        c[3].clear();
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            a[i][4]=getFirstClub(i);
            a[i][5]=getSecondClub(i);
            a[i][6]=getThirdClub(i);

            if(c[a[i][4]].size()<n/2){
            	c[a[i][4]].push_back(i);
            	ans+=a[i][a[i][4]];
            	sort(c[a[i][4]].begin(),c[a[i][4]].end(),cmp);
			}else{
				if(a[i][a[i][4]]>a[c[a[i][4]][n/2-1]][a[c[a[i][4]][n/2-1]][4]]-a[c[a[i][4]][n/2-1]][a[c[a[i][4]][n/2-1]][5]]){
                    c[a[c[a[i][4]][n/2-1]][5]].push_back(c[a[i][4]][n/2-1]);
                    ans-=a[c[a[i][4]][n/2-1]][a[c[a[i][4]][n/2-1]][4]]-a[c[a[i][4]][n/2-1]][a[c[a[i][4]][n/2-1]][5]];
                    c[a[i][4]].pop_back();
                    c[a[i][4]].push_back(i);
            	    ans+=a[i][a[i][4]];
            	    sort(c[a[i][4]].begin(),c[a[i][4]].end(),cmp);
                    sort(c[a[c[a[i][4]][n/2-1]][5]].begin(),c[a[c[a[i][4]][n/2-1]][5]].end(),cmp);
                }else{
            	    c[a[i][5]].push_back(i);
            	    ans+=a[i][a[i][5]];
            	    sort(c[a[i][5]].begin(),c[a[i][5]].end(),cmp);
                }
			}
        }
        cout<<ans<<endl;
    }
    return 0;
}
