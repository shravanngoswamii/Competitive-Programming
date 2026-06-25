// AUTHOR: Shravan Goswami

#include <bits/stdc++.h>
using namespace std;
 
bool ib(const string &s){
    if(s.size()%3) return false;
    int l=0, i=0, t=0;
    for(char c: s){
        if(c=='L') l++;
        else if(c=='I') i++;
        else if(c=='T') t++;
    }
    int x = s.size()/3;
    return (l==x && i==x && t==x);
}
 
char fi(char a, char b){
    if((a=='L' && b=='I') || (a=='I' && b=='L')) return 'T';
    if((a=='L' && b=='T') || (a=='T' && b=='L')) return 'I';
    if((a=='I' && b=='T') || (a=='T' && b=='I')) return 'L';
    return '?';
}
 
void cc(const string &s, int &l, int &i, int &t){
    l = i = t = 0;
    for(char c: s){
        if(c=='L') l++;
        else if(c=='I') i++;
        else if(c=='T') t++;
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        string s; cin >> s;
        if(n==1){
            cout << -1 << "\n";
            continue;
        }
        bool v=false;
        for(int j=0; j<(int)s.size()-1; j++){
            if(s[j]!=s[j+1]) { v=true; break; }
        }
        if(!v){
            if(ib(s)) cout << 0 << "\n";
            else cout << -1 << "\n";
            continue;
        }
        vector<int> w;
        int m = 2 * n;
        bool d=false;
        for(int op=0; op<m; op++){
            if(ib(s)){ d=true; break; }
            int cl, ci, ct;
            cc(s, cl, ci, ct);
            int sz = s.size();
            char ds;
            int mn = min({cl, ci, ct});
            if(cl==mn) ds = 'L';
            else if(ci==mn) ds = 'I';
            else ds = 'T';
            int j = -1;
            for(int k=0; k<(int)s.size()-1; k++){
                if(s[k]==s[k+1]) continue;
                char x = fi(s[k], s[k+1]);
                if(x==ds){ j=k; break; }
            }
            if(j==-1){
                for(int k=0; k<(int)s.size()-1; k++){
                    if(s[k]!=s[k+1]){ j=k; break; }
                }
            }
            if(j==-1) break;
            w.push_back(j+1);
            char ch = fi(s[j], s[j+1]);
            s.insert(s.begin()+j+1, ch);
        }
        if(ib(s)){
            cout << w.size() << "\n";
            for(auto x : w) cout << x << "\n";
        } else cout << -1 << "\n";
    }
    return 0;
}
