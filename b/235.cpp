#include<bits/stdc++.h>
using namespace std;
int siz;
long long f[(1<<18)][105];
bool chk[20];
int getbit(int mask,int k) {
    return ((mask>>(k-1)) & 1);
}

int cnt(int mask) {
    int tmp=0;
    for(int i=1;i<=siz;i++)
        if(getbit(mask,i)) tmp++;
   return tmp;
}

int main() {
    string s; int m; cin>>s>>m;
    siz=s.size();
    f[0][0]=1;
    for(int i=0;i< (1<<siz)-1 ; i++) {
        int num=cnt(i);
        for(int k=0;k<m;k++) {
            if(!f[i][k]) continue;
            memset(chk,0,sizeof(chk));
            for(int j=1;j<=siz;j++)
                if(getbit(i,j)==0) {
                    if((s[j-1]=='0' && num==0) || chk[s[j-1]-'0']) continue;
                    f[i+(1<<(j-1))][(10*k+(s[j-1]-'0'))%m]+=f[i][k];
                    chk[s[j-1]-'0']=1;
                    //cout<<num<<' '<<i+(1<<(j-1))<<' '<<(10*k+(s[j-1]-'0'))<<' '<<i<<' '<<k<<endl;
                }
        }
    }
    cout<<f[(1<<siz)-1][0]<<endl;
}
