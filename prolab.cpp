#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <string.h>


/*
160201103 EMRE SUALP
170201087 SILA SECGÝN

*/
int x[3][3],i,j,m[4][5];
int mp1,mp2,degerA,degerB,degerC,degerD,degerE,degerX,degerY,degerZ,degerT,n=0;
char giris_1,giris_2,cikis_1,cikis_2,bNok,yon;
char ch;

void denklemKur();
void yonCiz(int mp,char k);
void degerGir(int mp);
void draw_mp1(int mp1);
void draw_mp2(int mp2);
void caddeYon(int mp);
void draw_mp11(int x1,int y1,int x2,int y2);
void gaussElimination(int n,int degerA,int degerB,int degerC,int degerD,int degerE);
int main()
{
   x[0][0]=0;x[0][1]=0;x[0][2]=0;x[1][0]=0;x[1][1]=0;x[1][2]=0;x[2][0]=0;x[2][1]=0;x[2][2]=0;
   draw_mp1(mp1);
   draw_mp2(mp2);

   while(ch!='1' && ch!='2')
   {
       printf("\n");
       printf("1)Harita-1\n");
       printf("2)Harita-2\n");
       printf("Bir harita secimi yapiniz: ");
       scanf("%s",&ch);
   }

   closegraph();

   if(ch=='1')
   {
        printf("\nSeciminiz : Harita-1");
        draw_mp1(mp1);
        caddeYon(1);
        degerGir(1);
   }
   else
   {
        printf("\nSeciminiz : Harita-2");
        draw_mp2(mp2);
        caddeYon(2);
        degerGir(2);
   }

    getch();
   return 0;
}
void draw_mp11(int x1,int y1,int x2,int y2)
{
    int i ;
    for(i=0;i<=60;i++)
    {
        setcolor(RED);
        line(x1,y1,x1+(i*x2),y1+(i*y2));
        delay(30);
    }
    line(x1+(x2*60),y1+(y2*60),(x1+(x2*60)+(2*x2)),(y1+(y2*60)+(10*x2)));
    line(x1+(x2*60),y1+(y2*60),(x1+(x2*60)+(10*y2)),(y1+(y2*60)+(2*x2)));
}

void yonCiz(int mp,char k)
{


        if(bNok=='x' && yon=='t')
        {
            if(k=='a')
            {
                draw_mp11(230,135,-1,+1); // asagi A
                x[1][0]=1;
            }
            else if(k=='b')
            {
                draw_mp11(330,135,1,1); // asagi B
                x[0][1]=1;
            }
            else if(k=='c')
            {
                draw_mp11(230,375,-1,-1); // yukari C
                x[2][1]=2;
            }
            else if(k=='d')
            {
                draw_mp11(390,315,-1,1); // asagi D
                x[1][2]=1;
            }
            else
            {
                draw_mp11(310,240,-1,0);
                x[1][1]=2;
            }
        }
        else if(bNok=='x' && yon=='y')
        {
            if(k=='a')
            {
                draw_mp11(230,135,-1,+1); // asagi A
                x[1][0]=1;
            }
            else if(k=='b')
            {
                draw_mp11(330,135,1,1); // asagi B
                x[0][1]=1;
            }
            else if(k=='c')
            {
                draw_mp11(170,315,1,1); // asagi C
                 x[2][1]=1;
            }
            else if(k=='d')
            {
                draw_mp11(330,375,1,-1); //yukari D
                x[1][2]=2;
            }
            else
            {
               // draw_mp22(1,1);
               x[1][1]=2;
            }
        }
        else if(bNok=='x' && yon=='z')
        {
            if(k=='a')
            {
                draw_mp11(230,135,-1,+1);
                x[1][0]=1;

            }
            else if(k=='b')
            {
                draw_mp11(330,135,1,1);
                x[0][1]=1;
            }
            else if(k=='c')
            {
                draw_mp11(170,315,1,1);
                 x[2][1]=1;
            }
            else if(k=='d')
            {
                draw_mp11(390,315,-1,1);
                x[1][2]=1;
            }
            else
            {
                //draw_mp22(1,1);
            }
        }
        else if(bNok=='y' && yon=='x')
        {
            if(k=='a')
            {
               draw_mp11(170,195,1,-1); //yukari A
               x[1][0]=2;

            }
            else if(k=='b')
            {
               draw_mp11(390,195,-1,-1);
                x[0][1]=2;
            }
            else if(k=='c')
            {
                 draw_mp11(230,375,-1,-1); // yukari C
                 x[2][1]=2;
            }
            else if(k=='d')
            {
               draw_mp11(390,315,-1,1); // asagi D
               x[1][2]=1;
            }
            else
            {
                //draw_mp22(1,1);
            }
        }
        else if(bNok=='y' && yon=='t')
        {
            if(k=='a')
            {
                draw_mp11(230,135,-1,+1); //asagi A
                x[1][0]=1;

            }
            else if(k=='b')
            {
                draw_mp11(390,195,-1,-1);
                x[0][1]=2;
            }
            else if(k=='c')
            {
                draw_mp11(230,375,-1,-1); // yukari C
                 x[2][1]=2;
            }
            else if(k=='d')
            {
                draw_mp11(390,315,-1,1);// asagi D
                x[1][2]=1;
            }
            else
            {
                //draw_mp22(1,1);
            }
        }
        else if(bNok=='y' && yon=='z')
        {
            if(k=='a')
            {
                draw_mp11(230,135,-1,+1); // asagi A
                x[1][0]=1;

            }
            else if(k=='b')
            {
                draw_mp11(390,195,-1,-1);
                 x[0][1]=2;
            }
            else if(k=='c')
            {
                draw_mp11(170,315,1,1);
                 x[2][1]=1;
            }
            else if(k=='d')
            {
                draw_mp11(390,315,-1,1);
                 x[1][2]=1;
            }
            else
            {
                //draw_mp22(1,1);
            }
        }
        else if(bNok=='z' && yon=='x')
        {
           if(k=='a')
            {
               draw_mp11(170,195,1,-1); //yukari A
                x[1][0]=2;

            }
            else if(k=='b')
            {
                draw_mp11(390,195,-1,-1);
                 x[0][1]=2;
            }
            else if(k=='c')
            {
                draw_mp11(230,375,-1,-1); // yukari C
                 x[2][1]=2;
            }
            else if(k=='d')
            {
               draw_mp11(330,375,1,-1); //yukari D
                x[1][2]=2;
            }
            else
            {
               // draw_mp22(1,1);
            }
        }
        else if(bNok=='z' && yon=='y')
        {
            if(k=='a')
            {
               draw_mp11(170,195,1,-1); //yukari A
                x[1][0]=2;

            }
            else if(k=='b')
            {
                draw_mp11(330,135,1,1);
                 x[0][1]=1;
            }
            else if(k=='c')
            {
                draw_mp11(230,375,-1,-1); // yukari C
                 x[2][1]=2;
            }
            else if(k=='d')
            {
               draw_mp11(330,375,1,-1); //yukari D
                x[1][2]=2;
            }
            else
            {
               // draw_mp22(1,1);
            }
        }
        else if(bNok=='z' && yon=='t')
        {
            if(k=='a')
            {
                draw_mp11(230,135,-1,+1);
                 x[1][0]=1;

            }
            else if(k=='b')
            {
                draw_mp11(390,195,-1,-1);
                 x[0][1]=2;
            }
            else if(k=='c')
            {
                draw_mp11(230,375,-1,-1); // yukari C
                 x[2][1]=2;
            }
            else if(k=='d')
            {
                draw_mp11(330,375,1,-1); //yukari D
                 x[1][2]=2;
            }
            else
            {
                //draw_mp22(1,1);
            }
        }
        else if(bNok=='t' && yon=='x')
        {
            if(k=='a')
            {
               draw_mp11(170,195,1,-1); //yukari A
                x[1][0]=2;

            }
            else if(k=='b')
            {
                draw_mp11(390,195,-1,-1);
                 x[0][1]=2;
            }
            else if(k=='c')
            {
                draw_mp11(170,315,1,1); // asagi C
                 x[2][1]=1;
            }
            else if(k=='d')
            {
                draw_mp11(330,375,1,-1); //yukari D
                 x[1][2]=2;
            }
            else
            {
               // draw_mp22(1,1);
            }
        }
        else if(bNok=='t' && yon=='y')
        {
            if(k=='a')
            {
              draw_mp11(170,195,1,-1); //yukari A
               x[1][0]=2;

            }
            else if(k=='b')
            {
                draw_mp11(330,135,1,1);
                 x[0][1]=1;
            }
            else if(k=='c')
            {
                draw_mp11(170,315,1,1); // asagi C
                 x[2][1]=1;
            }
            else if(k=='d')
            {
               draw_mp11(330,375,1,-1); //yukari D
                x[1][2]=2;
            }
            else
            {
               // draw_mp22(1,1);
            }
        }
        else if(bNok=='t' && yon=='z')
        {
            if(k=='a')
            {
               draw_mp11(170,195,1,-1); //yukari A
                x[1][0]=2;
            }
            else if(k=='b')
            {
                draw_mp11(330,135,1,1);
                 x[0][1]=1;
            }
            else if(k=='c')
            {
                draw_mp11(170,315,1,1); // asagi C
                 x[2][1]=1;
            }
            else if(k=='d')
            {
                draw_mp11(390,315,-1,1);
                 x[1][2]=1;
            }
            else
            {
               // draw_mp22(1,1);
            }
        }
            printf("\n");


    }

void caddeYon(int mp)
{
    do
    {
        printf("\n\n----CADDE YONLERI----\n");
        printf("Birinci girisi giriniz: ");
        scanf("%s",&giris_1);
        if(giris_1=='x') x[0][0] = 1;
        else if(giris_1=='y') x[0][2]=1;
        else if(giris_1=='z') x[2][2]=1;
        else if(giris_1=='t') x[2][0]=1;
        printf("Ikinci girisi giriniz: ");
        scanf("%s",&giris_2);
        if(giris_2=='x') x[0][0] = 1;
        else if(giris_2=='y') x[0][2]=1;
        else if(giris_2=='z') x[2][2]=1;
        else if(giris_2=='t') x[2][0]=1;
        printf("Birinci cikisi giriniz: ");
        scanf("%s",&cikis_1);
        if(cikis_1=='x') x[0][0] = 2;
        else if(cikis_1=='y') x[0][2]=2;
        else if(cikis_1=='z') x[2][2]=2;
        else if(cikis_1=='t') x[2][0]=2;
        printf("Ikinci cikisi giriniz: ");
        scanf("%s",&cikis_2);
        if(cikis_2=='x') x[0][0] = 2;
        else if(cikis_2=='y') x[0][2]=2;
        else if(cikis_2=='z') x[2][2]=2;
        else if(cikis_2=='t') x[2][0]=2;
    } while((giris_1==giris_2) || (giris_1==cikis_1) || (giris_1==cikis_2) || (giris_2==cikis_1) || (giris_2==cikis_2) || (cikis_1==cikis_2));

    printf("\n");

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d  ",x[i][j]);
        }
        printf("\n");
    }

    printf("\n---- BASLANGIC NOKTALARI----\n");
    do
    {
        printf("A yolu icin baslangic Noktasi : ");
        scanf("%s",&bNok);
        printf("A yolunun yonu : ");
        scanf("%s",&yon);
    }while((bNok!=giris_1 && bNok!=giris_2) || (yon!=cikis_1 && yon!=cikis_2));
    yonCiz(mp,'a');
    do
    {
        printf("B yolu icin baslangic Noktasi : ");
        scanf("%s",&bNok);
        printf("B yolunun yonu : ");
        scanf("%s",&yon);
    }while((bNok!=giris_1 && bNok!=giris_2) || (yon!=cikis_1 && yon!=cikis_2));
    yonCiz(mp,'b');
    do
    {
        printf("C yolu icin baslangic Noktasi : ");
        scanf("%s",&bNok);
        printf("C yolunun yonu : ");
        scanf("%s",&yon);
    }while((bNok!=giris_1 && bNok!=giris_2) || (yon!=cikis_1 && yon!=cikis_2));
    yonCiz(mp,'c');
    do
    {
        printf("D yolu icin baslangic Noktasi : ");
        scanf("%s",&bNok);
        printf("D yolunun yonu : ");
        scanf("%s",&yon);
    }while((bNok!=giris_1 && bNok!=giris_2) || (yon!=cikis_1 && yon!=cikis_2));
    yonCiz(mp,'d');
    if(mp!=1)
    {
        do
        {
            printf("E yolu icin baslangic Noktasi : ");
            scanf("%s",&bNok);
            printf("E yolunun yonu : ");
            scanf("%s",&yon);
        }while((bNok!=giris_1 && bNok!=giris_2) || (yon!=cikis_1 && yon!=cikis_2));
        yonCiz(mp,'e');
    }

    printf("%c + %c = %c + %c \n \n", giris_1,giris_2,cikis_1,cikis_2);

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d  ",x[i][j]);
        }
        printf("\n");
    }
}

void degerGir(int mp)
{
    printf("\n----DEGERLER----\n");
    printf("A caddesi icin deger giriniz(Bilinmeyen icin -1 giriniz) : ");
    scanf("%d",&degerA);
    if(degerA==-1) n++;
    printf("B caddesi icin deger giriniz(Bilinmeyen icin -1 giriniz) : ");
    scanf("%d",&degerB);
    if(degerB==-1) n++;
    printf("C caddesi icin deger giriniz(Bilinmeyen icin -1 giriniz) : ");
    scanf("%d",&degerC);
    if(degerC==-1) n++;
    printf("D caddesi icin deger giriniz(Bilinmeyen icin -1 giriniz) : ");
    scanf("%d",&degerD);
    if(degerD==-1) n++;
    printf("X caddesi icin deger giriniz(Bilinmeyen icin -1 giriniz) : ");
    scanf("%d",&degerX);
    if(degerX==-1) n++;
    printf("Y caddesi icin deger giriniz(Bilinmeyen icin -1 giriniz) : ");
    scanf("%d",&degerY);
    if(degerY==-1) n++;
    printf("Z caddesi icin deger giriniz(Bilinmeyen icin -1 giriniz) : ");
    scanf("%d",&degerZ);
    if(degerZ==-1) n++;
    printf("T caddesi icin deger giriniz(Bilinmeyen icin -1 giriniz) : ");
    scanf("%d",&degerT);
    if(degerT==-1) n++;
    if(mp!=1)
    {
        printf("E caddesi icin deger giriniz(Bilinmeyen icin -1 giriniz) : ");
        scanf("%d",&degerE);
        if(degerE==-1) n++;
    }
    printf("Bilinmeyen deger sayisi : %d \n", n);
    printf("\n----Bilinen Degerler----\n");
    if(degerA!=-1) printf("A degeri : %d \n",degerA);
    if(degerB!=-1) printf("B degeri : %d \n",degerB);
    if(degerC!=-1) printf("C degeri : %d \n",degerC);
    if(degerD!=-1) printf("D degeri : %d \n",degerD);
    if(mp!=1 && degerE!=-1) printf("E degeri : %d \n",degerE);
    if(degerX!=-1) printf("X degeri : %d \n",degerX);
    if(degerY!=-1) printf("Y degeri : %d \n",degerY);
    if(degerZ!=-1) printf("Z degeri : %d \n",degerZ);
    if(degerT!=-1) printf("T degeri : %d \n",degerT);

    denklemKur();

}
void denklemKur()
{
    printf("\n\n---KURULAN DENKLEMLER---");

    //T YOLU ICIN
    if(x[2][0]==1)
    {
            if(x[1][0]==1 && x[2][1]==2)
            {
                printf("\nc-a=t ==> %d - %d = %d",degerC,degerA,degerT);
                if(degerA==-1 && degerC==-1)
                {
                    m[0][0]=-1;m[0][1]=0;m[0][2]=1;m[0][3]=0;m[0][4]=degerT;
                }
                else if(degerC==-1)
                {
                    m[0][0]=0;m[0][1]=0;m[0][2]=1;m[0][3]=0;m[0][4]=degerT+degerA;
                }
                else if(degerA==-1)
                {
                    m[0][0]=1;m[0][1]=0;m[0][2]=0;m[0][3]=0;m[0][4]=(degerT-degerC)*-1;
                }
            }
            if(x[1][0]==2 && x[2][1]==1)
            {
                printf("\na+c=t ==> %d - %d = %d",degerA,degerC,degerT);
                if(degerA==-1 && degerC==-1)
                {
                    m[0][0]=1;m[0][1]=0;m[0][2]=1;m[0][3]=0;m[0][4]=degerT;
                }
                else if(degerC==-1)
                {
                    m[0][0]=0;m[0][1]=0;m[0][2]=1;m[0][3]=0;m[0][4]=degerT-degerA;
                }
                else if(degerA==-1)
                {
                    m[0][0]=1;m[0][1]=0;m[0][2]=0;m[0][3]=0;m[0][4]=degerT-degerC;
                }
            }
            if(x[1][0]==1 && x[2][1]==1)
            {
                printf("\nc-a=t ==> %d - %d = %d",degerC,degerA,degerT);
                if(degerA==-1 && degerC==-1)
                {
                    m[0][0]=-1;m[0][1]=0;m[0][2]=1;m[0][3]=0;m[0][4]=degerT;
                }
                else if(degerC==-1)
                {
                    m[0][0]=0;m[0][1]=0;m[0][2]=1;m[0][3]=0;m[0][4]=degerT+degerA;
                }
                else if(degerA==-1)
                {
                    m[0][0]=1;m[0][1]=0;m[0][2]=0;m[0][3]=0;m[0][4]=(degerT-degerC)*-1;
                }
            }
            if(x[1][0]==2 && x[2][1]==2)
            {
                printf("\na-c=t ==> %d - %d = %d",degerA,degerC,degerT);
                if(degerA==-1 && degerC==-1)
                {
                    m[0][0]=1;m[0][1]=0;m[0][2]=-1;m[0][3]=0;m[0][4]=degerT;
                }
                else if(degerC==-1)
                {
                    m[0][0]=0;m[0][1]=0;m[0][2]=1;m[0][3]=0;m[0][4]=(degerT-degerA)*-1;
                }
                else if(degerA==-1)
                {
                    m[0][0]=1;m[0][1]=0;m[0][2]=0;m[0][3]=0;m[0][4]=degerT+degerC;
                }
            }
    }
    else
    {
            if(x[1][0]==1 && x[2][1]==2)
            {
                printf("\na+c=t ==> %d - %d = %d",degerA,degerC,degerT);
                if(degerA==-1 && degerC==-1)
                {
                    m[0][0]=1;m[0][1]=0;m[0][2]=1;m[0][3]=0;m[0][4]=degerT;
                }
                else if(degerC==-1)
                {
                    m[0][0]=0;m[0][1]=0;m[0][2]=1;m[0][3]=0;m[0][4]=degerT-degerA;
                }
                else if(degerA==-1)
                {
                    m[0][0]=1;m[0][1]=0;m[0][2]=0;m[0][3]=0;m[0][4]=degerT-degerC;
                }
            }
            if(x[1][0]==2 && x[2][1]==1)
            {
                printf("\na+c=t ==> %d - %d = %d",degerA,degerC,degerT);
                if(degerA==-1 && degerC==-1)
                {
                    m[0][0]=1;m[0][1]=0;m[0][2]=1;m[0][3]=0;m[0][4]=degerT;
                }
                else if(degerC==-1)
                {
                    m[0][0]=0;m[0][1]=0;m[0][2]=1;m[0][3]=0;m[0][4]=degerT-degerA;
                }
                else if(degerA==-1)
                {
                    m[0][0]=1;m[0][1]=0;m[0][2]=0;m[0][3]=0;m[0][4]=degerT-degerC;
                }
            }
            if(x[1][0]==1 && x[2][1]==1)
            {
                printf("\na-c=t ==> %d - %d = %d",degerA,degerC,degerT);
                if(degerA==-1 && degerC==-1)
                {
                    m[0][0]=1;m[0][1]=0;m[0][2]=-1;m[0][3]=0;m[0][4]=degerT;
                }
                else if(degerC==-1)
                {
                    m[0][0]=0;m[0][1]=0;m[0][2]=-1;m[0][3]=0;m[0][4]=degerT-degerA;
                }
                else if(degerA==-1)
                {
                    m[0][0]=1;m[0][1]=0;m[0][2]=0;m[0][3]=0;m[0][4]=degerT+degerC;
                }
            }
            if(x[1][0]==2 && x[2][1]==2)
            {
                printf("\nc-a=t ==> %d - %d = %d",degerC,degerA,degerT);
                if(degerA==-1 && degerC==-1)
                {
                    m[0][0]=-1;m[0][1]=0;m[0][2]=1;m[0][3]=0;m[0][4]=degerT;
                }
                else if(degerC==-1)
                {
                    m[0][0]=0;m[0][1]=0;m[0][2]=1;m[0][3]=0;m[0][4]=degerT+degerA;
                }
                else if(degerA==-1)
                {
                    m[0][0]=1;m[0][1]=0;m[0][2]=0;m[0][3]=0;m[0][4]=(degerT-degerC)*-1;
                }
            }
    }
    //Y YOLU ICIN
    if(x[0][2]==1)
    {

            if(x[0][1]==1 && x[1][2]==2)
            {
                printf("\nb+d=y ==> %d - %d = %d",degerB,degerD,degerY);
                if(degerB==-1 && degerD==-1)
                {
                    m[1][0]=0;m[1][1]=1;m[1][2]=0;m[1][3]=1;m[1][4]=degerY;
                }
                else if(degerD==-1)
                {
                    m[1][0]=0;m[1][1]=0;m[1][2]=0;m[1][3]=1;m[1][4]=degerY-degerB;
                }
                else if(degerB==-1)
                {
                    m[1][0]=0;m[1][1]=1;m[1][2]=0;m[1][3]=0;m[1][4]=degerY-degerD;
                }
            }
            if(x[0][1]==2 && x[1][2]==1)
            {
                printf("\nb+d=y ==> %d - %d = %d",degerB,degerD,degerY);
                if(degerB==-1 && degerD==-1)
                {
                    m[1][0]=0;m[1][1]=1;m[1][2]=0;m[1][3]=1;m[1][4]=degerY;
                }
                else if(degerD==-1)
                {
                    m[1][0]=0;m[1][1]=0;m[1][2]=0;m[1][3]=1;m[1][4]=degerY-degerB;
                }
                else if(degerB==-1)
                {
                    m[1][0]=0;m[1][1]=1;m[1][2]=0;m[1][3]=0;m[1][4]=degerY-degerD;
                }
            }
            if(x[0][1]==1 && x[1][2]==1)
            {
                printf("\nd-b=y ==> %d - %d = %d",degerD,degerB,degerY);
                if(degerB==-1 && degerD==-1)
                {
                    m[1][0]=0;m[1][1]=-1;m[1][2]=0;m[1][3]=1;m[1][4]=degerY;
                }
                else if(degerD==-1)
                {
                    m[1][0]=0;m[1][1]=0;m[1][2]=0;m[1][3]=1;m[1][4]=degerY+degerB;
                }
                else if(degerB==-1)
                {
                    m[1][0]=0;m[1][1]=1;m[1][2]=0;m[1][3]=0;m[1][4]=(degerY-degerD)*-1;
                }
            }
            if(x[0][1]==2 && x[1][2]==2)
            {
                printf("\nb-d=y ==> %d - %d = %d",degerB,degerD,degerY);
                if(degerB==-1 && degerD==-1)
                {
                    m[1][0]=0;m[1][1]=1;m[1][2]=0;m[1][3]=-1;m[1][4]=degerY;
                }
                else if(degerD==-1)
                {
                    m[1][0]=0;m[1][1]=0;m[1][2]=0;m[1][3]=-1;m[1][4]=degerY-degerB;
                }
                else if(degerB==-1)
                {
                    m[1][0]=0;m[1][1]=1;m[1][2]=0;m[1][3]=0;m[1][4]=degerY+degerD;
                }
            }
    }
    else
    {
            if(x[0][1]==1 && x[1][2]==2)
            {
                printf("\nb+d=y ==> %d - %d = %d",degerB,degerD,degerY);
                if(degerB==-1 && degerD==-1)
                {
                    m[1][0]=0;m[1][1]=1;m[1][2]=0;m[1][3]=1;m[1][4]=degerY;
                }
                else if(degerD==-1)
                {
                    m[1][0]=0;m[1][1]=0;m[1][2]=0;m[1][3]=1;m[1][4]=degerY-degerB;
                }
                else if(degerB==-1)
                {
                    m[1][0]=0;m[1][1]=1;m[1][2]=0;m[1][3]=0;m[1][4]=degerY-degerD;
                }
            }
            if(x[0][1]==2 && x[1][2]==1)
            {
                printf("\nb+d=y ==> %d - %d = %d",degerB,degerD,degerY);
                if(degerB==-1 && degerD==-1)
                {
                    m[1][0]=0;m[1][1]=1;m[1][2]=0;m[1][3]=1;m[1][4]=degerY;
                }
                else if(degerD==-1)
                {
                    m[1][0]=0;m[1][1]=0;m[1][2]=0;m[1][3]=1;m[1][4]=degerY-degerB;
                }
                else if(degerB==-1)
                {
                    m[1][0]=0;m[1][1]=1;m[1][2]=0;m[1][3]=0;m[1][4]=degerY-degerD;
                }
            }
            if(x[0][1]==1 && x[1][2]==1)
            {
                printf("\nb-d=y ==> %d - %d = %d",degerB,degerD,degerY);
                if(degerB==-1 && degerD==-1)
                {
                    m[1][0]=0;m[1][1]=1;m[1][2]=0;m[1][3]=-1;m[1][4]=degerY;
                }
                else if(degerD==-1)
                {
                    m[1][0]=0;m[1][1]=0;m[1][2]=0;m[1][3]=1;m[1][4]=(degerY-degerB)*-1;
                }
                else if(degerB==-1)
                {
                    m[1][0]=0;m[1][1]=1;m[1][2]=0;m[1][3]=0;m[1][4]=degerY+degerD;
                }
            }
            if(x[0][1]==2 && x[1][2]==2)
            {
                printf("\nd-b=y ==> %d - %d = %d",degerD,degerB,degerY);
                if(degerB==-1 && degerD==-1)
                {
                    m[1][0]=0;m[1][1]=-1;m[1][2]=0;m[1][3]=1;m[1][4]=degerY;
                }
                else if(degerD==-1)
                {
                    m[1][0]=0;m[1][1]=0;m[1][2]=0;m[1][3]=1;m[1][4]=degerY+degerB;
                }
                else if(degerB==-1)
                {
                    m[1][0]=0;m[1][1]=1;m[1][2]=0;m[1][3]=0;m[1][4]=(degerY-degerD)*-1;
                }
            }
    }
    //X YOLU ICIN
    if(x[0][0]==1)
    {
            if(x[1][0]==1 && x[0][1]==2)
            {
                printf("\na-b=x ==> %d - %d = %d",degerA,degerB,degerX);
                if(degerA==-1 && degerB==-1)
                {
                    m[2][0]=1;m[2][1]=-1;m[2][2]=0;m[2][3]=0;m[2][4]=degerX;
                }
                else if(degerB==-1)
                {
                    m[2][0]=0;m[2][1]=1;m[2][2]=0;m[2][3]=0;m[2][4]=(degerX-degerA)*-1;
                }
                else if(degerA==-1)
                {
                    m[2][0]=1;m[2][1]=0;m[2][2]=0;m[2][3]=0;m[2][4]=degerX+degerB;
                }
            }
            if(x[1][0]==2 && x[0][1]==1)
            {
                printf("\nb-a=x ==> %d - %d = %d",degerB,degerA,degerX);
                if(degerA==-1 && degerB==-1)
                {
                    m[2][0]=-1;m[2][1]=1;m[2][2]=0;m[2][3]=0;m[2][4]=degerX;
                }
                else if(degerB==-1)
                {
                    m[2][0]=0;m[2][1]=1;m[2][2]=0;m[2][3]=0;m[2][4]=degerX+degerA;
                }
                else if(degerA==-1)
                {
                    m[2][0]=1;m[2][1]=0;m[2][2]=0;m[2][3]=0;m[2][4]=(degerX-degerB)*-1;
                }
            }
            if(x[1][0]==1 && x[0][1]==1)
            {
                printf("\na+b=x ==> %d - %d = %d",degerA,degerB,degerX);
                if(degerA==-1 && degerB==-1)
                {
                    m[2][0]=1;m[2][1]=1;m[2][2]=0;m[2][3]=0;m[2][4]=degerX;
                }
                else if(degerB==-1)
                {
                    m[2][0]=0;m[2][1]=1;m[2][2]=0;m[2][3]=0;m[2][4]=degerX-degerA;
                }
                else if(degerA==-1)
                {
                    m[2][0]=1;m[2][1]=0;m[2][2]=0;m[2][3]=0;m[2][4]=degerX-degerB;
                }
            }
            if(x[1][0]==2 && x[0][1]==2)
            {
                printf("\nb-a=x ==> %d - %d = %d",degerB,degerA,degerX);
                if(degerA==-1 && degerB==-1)
                {
                    m[2][0]=1;m[2][1]=-1;m[2][2]=0;m[2][3]=0;m[2][4]=degerX;
                }
                else if(degerB==-1)
                {
                    m[2][0]=0;m[2][1]=1;m[2][2]=0;m[2][3]=0;m[2][4]=degerX+degerA;
                }
                else if(degerA==-1)
                {
                    m[2][0]=1;m[2][1]=0;m[2][2]=0;m[2][3]=0;m[2][4]=(degerX-degerB)*-1;
                }
            }
    }
    else
    {
            if(x[1][0]==1 && x[0][1]==2)
            {
                printf("\nb-a=x ==> %d - %d = %d",degerB,degerA,degerX);
                if(degerA==-1 && degerB==-1)
                {
                    m[2][0]=1;m[2][1]=-1;m[2][2]=0;m[2][3]=0;m[2][4]=degerX;
                }
                else if(degerB==-1)
                {
                    m[2][0]=0;m[2][1]=1;m[2][2]=0;m[2][3]=0;m[2][4]=degerX+degerA;
                }
                else if(degerA==-1)
                {
                    m[2][0]=1;m[2][1]=0;m[2][2]=0;m[2][3]=0;m[2][4]=(degerX-degerB)*-1;
                }
            }
            if(x[1][0]==2 && x[0][1]==1)
            {
                printf("\na-b=x ==> %d - %d = %d",degerA,degerB,degerX);
                if(degerA==-1 && degerB==-1)
                {
                    m[2][0]=1;m[2][1]=-1;m[2][2]=0;m[2][3]=0;m[2][4]=degerX;
                }
                else if(degerB==-1)
                {
                    m[2][0]=0;m[2][1]=1;m[2][2]=0;m[2][3]=0;m[2][4]=(degerX-degerA)*-1;
                }
                else if(degerA==-1)
                {
                    m[2][0]=1;m[2][1]=0;m[2][2]=0;m[2][3]=0;m[2][4]=degerX+degerB;
                }
            }
            if(x[1][0]==1 && x[0][1]==1)
            {
                printf("\na-b=x ==> %d - %d = %d",degerA,degerB,degerX);
                if(degerA==-1 && degerB==-1)
                {
                    m[2][0]=1;m[2][1]=-1;m[2][2]=0;m[2][3]=0;m[2][4]=degerX;
                }
                else if(degerB==-1)
                {
                    m[2][0]=0;m[2][1]=1;m[2][2]=0;m[2][3]=0;m[2][4]=(degerX-degerA)*-1;
                }
                else if(degerA==-1)
                {
                    m[2][0]=1;m[2][1]=0;m[2][2]=0;m[2][3]=0;m[2][4]=degerX+degerB;
                }
            }
            if(x[1][0]==2 && x[0][1]==2)
            {
                printf("\na+b=x ==> %d - %d = %d",degerA,degerB,degerX);
                if(degerA==-1 && degerB==-1)
                {
                    m[2][0]=1;m[2][1]=1;m[2][2]=0;m[2][3]=0;m[2][4]=degerX;
                }
                else if(degerB==-1)
                {
                    m[2][0]=0;m[2][1]=1;m[2][2]=0;m[2][3]=0;m[2][4]=degerX-degerA;
                }
                else if(degerA==-1)
                {
                    m[2][0]=1;m[2][1]=0;m[2][2]=0;m[2][3]=0;m[2][4]=degerX-degerB;
                }
            }
    }

    //Z YOLU ICIN
    if(x[2][2]==1)
    {
            if(x[2][1]==1 && x[1][2]==2)
            {
                printf("\nc-d=z ==> %d - %d = %d",degerC,degerD,degerZ);
                if(degerC==-1 && degerD==-1)
                {
                    m[3][0]=0;m[3][1]=0;m[3][2]=1;m[3][3]=-1;m[3][4]=degerZ;
                }
                else if(degerD==-1)
                {
                    m[3][0]=0;m[3][1]=0;m[3][2]=0;m[3][3]=1;m[3][4]=(degerZ-degerC)*-1;
                }
                else if(degerC==-1)
                {
                    m[3][0]=0;m[3][1]=0;m[3][2]=1;m[3][3]=0;m[3][4]=degerZ+degerD;
                }
            }
            if(x[2][1]==2 && x[1][2]==1)
            {
                printf("\nd-c=z ==> %d - %d = %d",degerD,degerC,degerZ);
                if(degerC==-1 && degerD==-1)
                {
                    m[3][0]=0;m[3][1]=0;m[3][2]=-1;m[3][3]=1;m[3][4]=degerZ;
                }
                else if(degerD==-1)
                {
                    m[3][0]=0;m[3][1]=0;m[3][2]=0;m[3][3]=1;m[3][4]=degerZ+degerC;
                }
                else if(degerC==-1)
                {
                    m[3][0]=0;m[3][1]=0;m[3][2]=1;m[3][3]=0;m[3][4]=(degerZ-degerD)*-1;
                }
            }
            if(x[2][1]==1 && x[1][2]==1)
            {
                printf("\nd-c=z ==> %d - %d = %d",degerD,degerC,degerZ);
                if(degerC==-1 && degerD==-1)
                {
                    m[3][0]=0;m[3][1]=0;m[3][2]=-1;m[3][3]=1;m[3][4]=degerZ;
                }
                else if(degerD==-1)
                {
                    m[3][0]=0;m[3][1]=0;m[3][2]=0;m[3][3]=1;m[3][4]=degerZ+degerC;
                }
                else if(degerC==-1)
                {
                    m[3][0]=0;m[3][1]=0;m[3][2]=1;m[3][3]=0;m[3][4]=(degerZ-degerD)*-1;
                }
            }
            if(x[2][1]==2 && x[1][1]==2)
            {
                printf("\nc+d=z ==> %d - %d = %d",degerC,degerD,degerZ);
                if(degerC==-1 && degerD==-1)
                {
                    m[3][0]=0;m[3][1]=0;m[3][2]=1;m[3][3]=1;m[3][4]=degerZ;
                }
                else if(degerD==-1)
                {
                    m[3][0]=0;m[3][1]=0;m[3][2]=0;m[3][3]=1;m[3][4]=degerZ-degerC;
                }
                else if(degerC==-1)
                {
                    m[3][0]=0;m[3][1]=0;m[3][2]=1;m[3][3]=0;m[3][4]=degerZ-degerD;
                }
            }
    }
    else
    {
            if(x[2][1]==1 && x[1][2]==2)
            {
                printf("\nc-d=z ==> %d - %d = %d",degerC,degerD,degerZ);
                if(degerC==-1 && degerD==-1)
                {
                    m[3][0]=0;m[3][1]=0;m[3][2]=1;m[3][3]=-1;m[3][4]=degerZ;
                }
                else if(degerD==-1)
                {
                    m[3][0]=0;m[3][1]=0;m[3][2]=0;m[3][3]=1;m[3][4]=(degerZ-degerC)*-1;
                }
                else if(degerC==-1)
                {
                    m[3][0]=0;m[3][1]=0;m[3][2]=1;m[3][3]=0;m[3][4]=degerZ+degerD;
                }
            }
            if(x[2][1]==2 && x[1][2]==1)
            {
                printf("\nd-c=z ==> %d - %d = %d",degerD,degerC,degerZ);
                if(degerC==-1 && degerD==-1)
                {
                    m[3][0]=0;m[3][1]=0;m[3][2]=-1;m[3][3]=1;m[3][4]=degerZ;
                }
                else if(degerD==-1)
                {
                    m[3][0]=0;m[3][1]=0;m[3][2]=0;m[3][3]=1;m[3][4]=degerZ+degerC;
                }
                else if(degerC==-1)
                {
                    m[3][0]=0;m[3][1]=0;m[3][2]=1;m[3][3]=0;m[3][4]=(degerZ-degerD)*-1;
                }
            }
            if(x[2][1]==1 && x[1][2]==1)
            {
                printf("\nc+d=z ==> %d - %d = %d",degerC,degerD,degerZ);
                if(degerC==-1 && degerD==-1)
                {
                    m[3][0]=0;m[3][1]=0;m[3][2]=1;m[3][3]=1;m[3][4]=degerZ;
                }
                else if(degerD==-1)
                {
                    m[3][0]=0;m[3][1]=0;m[3][2]=0;m[3][3]=1;m[3][4]=degerZ-degerC;
                }
                else if(degerC==-1)
                {
                    m[3][0]=0;m[3][1]=0;m[3][2]=1;m[3][3]=0;m[3][4]=degerZ-degerD;
                }
            }
            if(x[2][1]==2 && x[1][1]==2)
            {
                printf("\nc-d=z ==> %d - %d = %d",degerC,degerD,degerZ);
                if(degerC==-1 && degerD==-1)
                {
                    m[3][0]=0;m[3][1]=0;m[3][2]=1;m[3][3]=-1;m[3][4]=degerZ;
                }
                else if(degerD==-1)
                {
                    m[3][0]=0;m[3][1]=0;m[3][2]=0;m[3][3]=-1;m[3][4]=degerZ-degerC;
                }
                else if(degerC==-1)
                {
                    m[3][0]=0;m[3][1]=0;m[3][2]=1;m[3][3]=0;m[3][4]=degerZ+degerD;
                }
            }
    }
    if(degerX==-1 && degerY==-1) printf("\nx+y=z+t ==> x + y = %d  ",degerZ+degerT);
    if(degerX==-1 && degerZ==-1) printf("\nx+z=y+t ==> x + z = %d  ",degerY+degerT);
    if(degerX==-1 && degerT==-1) printf("\nx+t=y+z ==> x + t = %d  ",degerY+degerZ);
    if(degerY==-1 && degerZ==-1) printf("\ny+z=t+x ==> y + z = %d  ",degerT+degerX);
    if(degerY==-1 && degerT==-1) printf("\ny+t=z+x ==> y + t = %d  ",degerZ+degerX);
    if(degerT==-1 && degerZ==-1) printf("\nt+z=x+y ==> t + z = %d  ",degerX+degerY);

    printf("\n");
    for(i=0;i<4;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%d  ",m[i][j]);
        }
        printf("\n");
    }

}
/*void gaussElimination(int n)
{
    int i,j,k;
    float t[20][20],c,y[10],toplam=0.0;
    for(j=1; j<=n; j++)
    {
        for(i=1; i<=n; i++)
        {
            if(i>j)
            {
                c=t[i][j]/t[j][j];
                for(k=1; k<=n+1; k++)
                {
                    t[i][k]=t[i][k]-c*t[j][k];
                }
            }
        }
    }
    y[n]=t[n][n+1]/t[n][n];

    for(i=n-1; i>=1; i--)
    {
        toplam=0;
        for(j=i+1; j<=n; j++)
        {
            toplam=toplam+t[i][j]*y[j];
        }
        y[i]=(t[i][n+1]-toplam)/t[i][i];
    }
    printf("\nCozum :  \n");
    for(i=1; i<=n; i++)
    {
        printf("\nx%d=%f\t",i,y[i]);
    }
} */

void draw_mp1(int mp1)
{
    mp1 = initwindow(600, 500, "Harita-1");
    //circle-1
    setcolor(RED);
    circle(280,250,150);
    floodfill(280,250,RED);

    //circle-2
    setfillstyle(SOLID_FILL,BLACK);
    circle(280,250,100);
    floodfill(281,251,RED);

    //upper bar
    setfillstyle(SOLID_FILL,WHITE);
    bar(250,0,310,105);
    //right bar
    bar(425,220,725,280);
    //left bar
    bar(0,220,135,280);
    //down bar
    bar(250,395,310,500);


    setfillstyle(SOLID_FILL,MAGENTA);
    fillellipse(280,50, 15, 20);
    fillellipse(280,450, 15, 20);
    fillellipse(60,250, 20, 15);
    fillellipse(485,250, 20, 15);

    setfillstyle(SOLID_FILL,CYAN);
    fillellipse(365,160, 17, 17);
    fillellipse(195,160, 17, 17);
    fillellipse(365,340, 17, 17);
    fillellipse(195,340, 17, 17);

    setcolor(WHITE);
    outtextxy(275, 445, "Z");
    outtextxy(55, 240, "T");
    outtextxy(480, 240, "Y");
    outtextxy(360, 155, "B");
    outtextxy(190, 155, "A");
    outtextxy(360, 335, "D");
    outtextxy(275, 45, "X");
    outtextxy(190, 335, "C");
}
void draw_mp2(int mp2)
{
    mp2 = initwindow(600, 500, "Harita-2");

    //circle-1
    setcolor(RED);
    circle(280,250,150);
    floodfill(280,250,RED);

    //circle-2
    setfillstyle(SOLID_FILL,BLACK);
    circle(280,250,100);
    floodfill(281,251,RED);

    //upper bar
    setfillstyle(SOLID_FILL,WHITE);
    bar(250,0,310,105);


    //right bar
    bar(425,220,725,280);
    //left bar
    bar(0,220,135,280);
    //down bar
    bar(250,395,310,500);
    //middle bar
    bar(180,220,380,280);


    setfillstyle(SOLID_FILL,MAGENTA);
    fillellipse(280,50, 15, 20);
    fillellipse(280,450, 15, 20);
    fillellipse(60,250, 20, 15);
    fillellipse(485,250, 20, 15);
    setfillstyle(SOLID_FILL,CYAN);
    fillellipse(285,250, 20, 15);
    fillellipse(365,160, 17, 17);
    fillellipse(195,160, 17, 17);
    fillellipse(365,340, 17, 17);
    fillellipse(195,340, 17, 17);

    setcolor(WHITE);
    outtextxy(275, 445, "Z");
    outtextxy(55, 240, "T");
    outtextxy(480, 240, "Y");
    outtextxy(360, 155, "B");
    outtextxy(190, 155, "A");
    outtextxy(360, 335, "D");
    outtextxy(275, 45, "X");
    outtextxy(190, 335, "C");
    outtextxy(280,240, "E");
}
