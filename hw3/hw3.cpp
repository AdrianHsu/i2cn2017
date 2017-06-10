//http://ducslectures.blogspot.tw/p/blog-page_20.html
//http://www2.ic.uff.br/~michael/kr1999/4-network/4_02-algor.htm
//https://pl4programs.blogspot.tw/2015/04/implementation-of-distance-vector.html

#include<stdio.h>
#include<iostream>
using namespace std;

#define inf INT_MAX

struct node
{
   unsigned dist[9];
   unsigned from[9];
} DVR[9];
int main()
{
   unsigned costmat[9][9] = { { 0, 4, inf, inf, inf, inf, inf, 8, inf },
                         { 4, 0, 8, inf, inf, inf, inf, 11, inf },
                         { inf, 8, 0, 7, inf, 4, inf, inf, 2 },
                         { inf, inf, 7, 0, 9, 14, inf, inf, inf },
                         { inf, inf, inf, 9, 0, 10, inf, inf, inf },
                         { inf, inf, 4, 14, 10, 0, 2, inf, inf },
                         { inf, inf, inf, inf, inf, 2, 0, 1, 6 },
                         { 8, 11, inf, inf, inf, inf, 1, 0, 7 },
                         { inf, inf, 2, inf, inf, inf, 6, 7, 0} };
   int nodes = 9, i, j, k;

   for(i = 0; i < nodes; i++)
    {
       for(j = 0; j < nodes; j++)
       {
           DVR[i].dist[j] = costmat[i][j]; //initialise the distance equal to cost matrix
           DVR[i].from[j] = j;
       }
   }
   for(i = 0; i < nodes; i++) {//We choose arbitary vertex k and we calculate the
   //direct distance from the node i to k using the cost matrix and add the distance from k to node j
       for(j = i+1; j < nodes; j++) {
           for(k = 0; k < nodes; k++) {
               if(DVR[i].dist[j] > costmat[i][k] + DVR[k].dist[j])
               {   //We calculate the minimum distance
                   DVR[i].dist[j] = DVR[i].dist[k] + DVR[k].dist[j];
                   DVR[j].dist[i] = DVR[i].dist[j];
                   DVR[i].from[j] = k;
                   DVR[j].from[i] = k;
               }
           }
       }
   }
   for(i = 0; i < nodes; i++)
   {
       cout<<"\n\n For router: "<<i;
       for(j = 0; j < nodes; j++)
           cout<<"\t\n node "<<j<<" via "<<DVR[i].from[j]<<" Distance "<<DVR[i].dist[j];
   }
   cout<<" \n\n ";
   return 0;
}
