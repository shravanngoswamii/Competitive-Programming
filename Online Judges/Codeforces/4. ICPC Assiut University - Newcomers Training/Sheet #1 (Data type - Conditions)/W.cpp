    #include<bits/stdc++.h>
    using namespace std;
    int main ()
    {
        int t;
        cin>>t;
        while(t--)
        {
            int p,q,r,s,u,v,i,j;
            cin>>p;
            int a[p];
            int b[p];
            u=0;
            v=0;
            for(i=0;i<p;i++)
            {
                cin>>a[i];
                if(i==0)
                {
                    continue;
                }
                if(a[i]==a[i-1])
                continue;
                else
                {
                   for(j=u;j<i;j++)
                   {
                       b[j]=i;
                       u++;
                   }
                }
             }
             cin>>q;
             for(i=u;i<p;i++)
             {
                 b[i]=INT_MAX;
             }
             for(i=0;i<q;i++)
             {
                 cin>>r>>s;
                 u=r-1;
                 v=s-1;
                 if(b[u]<=v)
                 cout<<u+1<<" "<<b[u]+1;
                 else
                 cout<<"-1"<<" "<<"-1";
                 cout<<endl;
             }
             cout<<endl;
        }
        return 0;
    }