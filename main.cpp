#include <iostream>
#include <stack>
#include <stdlib.h>
#include <cmath>

using namespace std;

int globalsize=0;



class punkt
{
public:
    int x,y;
};


punkt p0;

punkt nextToTop(stack<punkt> &Punkt)
{
    punkt punktt = Punkt.top();
    Punkt.pop();
    punkt temp = Punkt.top();
    Punkt.push(punktt);
    return temp;
}


int dystans(punkt p1, punkt p2)
{
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}



int polozenie(punkt p, punkt q, punkt r)
{
    int temp = (q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);

    if (temp == 0) return 0;
    else if(temp>0) return 1;
    else return 2;
}



int porownanie(const void *vp1, const void *vp2)
{
    punkt *p1 = (punkt *)vp1;
    punkt *p2 = (punkt *)vp2;

    int o = polozenie(p0, *p1, *p2);
    if (o == 0)
    {
        if(dystans(p0, *p2) >= dystans(p0, *p1))
        {
            return -1;
        }
        else return 1;
    }
    else if(o == 2)
        return -1;
    else return 1;

}


stack<punkt> wyznaczaniepolozenia(punkt *points, int n)
{
    int ymin = points[0].y;
    int min=0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
        {
            ymin = points[i].y;
            min = i;
        }
    }

    swap(points[0], points[min]);
    p0 = points[0];

    qsort(&points[1], n-1, sizeof(punkt), porownanie);

    int m = 1;
    for (int i = 1; i<n; i++)
    {
        while ((i<n-1)&&(polozenie(p0, points[i], points[i + 1]) == 0))
        {
            i++;
        }

        points[m] = points[i];
        m++;
    }

    if (m<3)
    {
        stack<punkt> empty;
        return empty;
    }
    stack<punkt> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);
    globalsize=globalsize+3;


    for (int i = 3; i < m; i++)
    {
        while (polozenie(nextToTop(S), S.top(), points[i])!= 2)
        {
            S.pop();
            globalsize--;
        }
        S.push(points[i]);
        globalsize++;
    }

return S;
}



int strona(punkt p1, punkt p2, punkt p3)
{
    int wektilocz =p1.x*p2.y+p2.x*p3.y+p3.x*p1.y-p3.x*p2.y-p1.x*p3.y-p2.x*p1.y;


    if(wektilocz==0)                    // na prostej
    {
        float p2_p3x=p3.x-p2.x;
        float p1_p2x=p2.x-p1.x;
        float p1_p3x=p3.x-p1.x;

        float p2_p3y=p3.y-p2.y;
        float p1_p2y=p2.y-p1.y;
        float p1_p3y=p3.y-p1.y;

        float p2_p3=sqrt(pow(p2_p3x,2)+pow(p2_p3y,2));
        float p1_p2=sqrt(pow(p1_p2x,2)+pow(p1_p2y,2));
        float p1_p3=sqrt(pow(p1_p3x,2)+pow(p1_p3y,2));

        if(p2_p3==p1_p2+p1_p3)
        {
            return 5000;
        }
        else{
         return 1;
        }
    }
    else if(wektilocz<0){   //srodek
        return 1;}
    else if(wektilocz>0){   //poza
        return -1;
    }
    return 9999;
}


int wsrodkuczynie(punkt tab[],punkt pkt)
{
    int iloscprostych=0;
    for(int j=0;j<globalsize-1;j++)
    {
        iloscprostych=iloscprostych+strona(pkt, tab[j],tab[j+1]);
    }
    iloscprostych=iloscprostych+strona(pkt, tab[globalsize-1],tab[0]);

    if(iloscprostych==globalsize)
    {
        return 1;
    }
    else if(iloscprostych>2000)
    {
        return 0;
    }
    else if(iloscprostych<globalsize)
    {
        return -1;
    }
    return 8888;
}



int main()
{
    int wielkosc,iloscpkt;
    cin>>wielkosc;
    punkt points[wielkosc];

    for(int i=0;i<wielkosc;i++)
    {
        cin>>points[i].x;
        cin>>points[i].y;
    }

    stack<punkt> S;
    S=wyznaczaniepolozenia(points, wielkosc);

    punkt otoczka[globalsize];
    int j=0;
    while (!S.empty())
    {
        punkt p = S.top();
        otoczka[j].x=p.x;
        otoczka[j].y=p.y;
        S.pop();
        j++;
    }

    cin>>iloscpkt;
    punkt checkpkt;
    for(int i=0;i<iloscpkt;i++)
    {
        cin>>checkpkt.x>>checkpkt.y;
        cout<<wsrodkuczynie(otoczka,checkpkt)<<endl;
    }



    return 0;
}
