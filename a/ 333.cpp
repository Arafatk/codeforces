include<bits/stdc++.h>
using namespace std;

int graph[401][401];
int train[401];
int car[401];
int n,m;

const int INF = 100000009;

void path_car()
{
   int i;
   
   car[1] = 0;
   
   deque<int> Q;
   
   Q.push_front(1);
   
   while(!Q.empty())
   {
      int here = Q.front();
      Q.pop_front();
      
      if(here == n)
         break;
         
      for(i=1; i <=n; i++)
      {
         if(graph[here][i] == 2)
         {
            if(car[here] + 1 < car[i])
            {
               car[i] = car[here] + 1;
               Q.push_back(i);
            }
         }
      }
   }
}


void path_train()
{
   int i,w;
   
   train[1] = 0;
   
   deque<int> Q;
   
   Q.push_front(1);
   
   while(!Q.empty())
   {
      int here = Q.front();
      Q.pop_front();
      
      if(here == n)
         break;
      
      for(i=1; i <=n; i++)
      {
         if(graph[here][i] == 1)
         {
            if(train[here] + 1 < train[i])
            {
               train[i] = train[here] + 1;
               Q.push_back(i);
            }
         }
      }
   }
}

int main()
{
   int i,j,x,y,res;
   
   cin>>n>>m;
   
   
   for(i=0; i <m; i++)
   {
      cin>>x>>y;
      
      graph[x][y] = graph[y][x] = 1;
   }
   
   for(i=1 ; i <=n ; i++)
   {
      train[i] = car[i] = INF;
      for(j=1; j <=n; j++)
      {
         if( !graph[i][j] && i!= j)
            graph[i][j] = graph[j][i] = 2;
      }
   }
      
   /*for(i=1 ; i <=n ; i++)
   {
      for(j=1; j <=n; j++)
         cout<<graph[i][j]<<" ";
      cout<<endl;
   }*/
   
   path_train();
   path_car();
   
   res = max(train[n], car[n]);
   if(res == INF)
      cout<<-1;
   else
      cout<<res;
   //cout<<train[n];
   return 0;
}
