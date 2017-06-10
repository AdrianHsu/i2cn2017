//references:
//http://ducslectures.blogspot.tw/p/blog-page_20.html
//http://www2.ic.uff.br/~michael/kr1999/4-network/4_02-algor.htm
//https://pl4programs.blogspot.tw/2015/04/implementation-of-distance-vector.html

#include<stdio.h>
#include<iostream>
using namespace std;

#define inf INT_MAX
#define NUM 9
struct node
{
   unsigned dist[NUM];
   unsigned from[NUM];
} DVR[NUM];
int main()
{
   // cost matrix
   unsigned costmat[NUM][NUM] = {{ 0, 4, inf, inf, inf, inf, inf, 8, inf },
                             { 4, 0, 8, inf, inf, inf, inf, 11, inf },
                             { inf, 8, 0, 7, inf, 4, inf, inf, 2 },
                             { inf, inf, 7, 0, 9, 14, inf, inf, inf },
                             { inf, inf, inf, 9, 0, 10, inf, inf, inf },
                             { inf, inf, 4, 14, 10, 0, 2, inf, inf },
                             { inf, inf, inf, inf, inf, 2, 0, 1, 6 },
                             { 8, 11, inf, inf, inf, inf, 1, 0, 7 },
                             { inf, inf, 2, inf, inf, inf, 6, 7, 0}};

   int i, j, k;
   // initialization:
   for(i = 0; i < NUM; i++)
    {
       for(j = 0; j < NUM; j++)
       {
           DVR[i].dist[j] = costmat[i][j];
           DVR[i].from[j] = j;
       }
   }
   cout << "----------- initial distance vectors -----------" << endl;
   for(i = 0; i < NUM; i++)
   {
       cout << "\n\n For router: " << i;
       for(j = 0; j < NUM; j++) {

           cout << "\t\n (node " << j << " via " << DVR[i].from[j] << ") The distance is: ";
           if(DVR[i].dist[j] == INT_MAX) cout << "inf";
           else cout << DVR[i].dist[j];
       }
   }
   for(i = 0; i < NUM; i++) {
       for(j = 0; j < NUM; j++) {
           for(k = 0; k < NUM; k++) {
               if(DVR[i].dist[j] > costmat[i][k] + DVR[k].dist[j])
               {
                   DVR[i].dist[j] = DVR[i].dist[k] + DVR[k].dist[j];
                   DVR[j].dist[i] = DVR[i].dist[j];
                   DVR[i].from[j] = k;
                   DVR[j].from[i] = k;
               }
           }
       }
   }
   cout << "\n\n----------- When the algorithm converges -----------" << endl;
   for(i = 0; i < NUM; i++)
   {
       cout << "\n\n For router: " << i;
       for(j = 0; j < NUM; j++)
       cout << "\t\n (node " << j << " via " << DVR[i].from[j] << ") The distance is: " << DVR[i].dist[j];
   }
   cout<<" \n\n ";
   return 0;
}
