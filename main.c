// 150202091  Melike AYDIN
#include <stdio.h>
#include <stdlib.h>
#define SONSUZLUK 100000
#define MAX 23

void islem1(int sehirMatrisi[MAX][MAX], int sehir)
{
    int gecici[MAX][MAX],mesafe[MAX],once[MAX];
    int ziyaretEdilen[MAX],sayac,kisaMesafe,sonraki,i,j;

    for(i=0;i<23;i++)
        for(j=0;j<23;j++)
            if(sehirMatrisi[i][j]==0)
                gecici[i][j]=SONSUZLUK;
            else
                gecici[i][j]=sehirMatrisi[i][j];

    for(i=0;i<23;i++)
    {
        mesafe[i]=gecici[sehir][i];
        once[i]=sehir;
        ziyaretEdilen[i]=0;
    }
    mesafe[sehir]=0;
    ziyaretEdilen[sehir]=1;
    sayac=1;

    while(sayac<22)
    {
        kisaMesafe=SONSUZLUK;
        for(i=0;i<23;i++)
            if(mesafe[i]<kisaMesafe&&!ziyaretEdilen[i])
            {
                kisaMesafe=mesafe[i];
                sonraki=i;
            }
            ziyaretEdilen[sonraki]=1;
            for(i=0;i<23;i++)
                if(!ziyaretEdilen[i])
                    if(kisaMesafe+gecici[sonraki][i]<mesafe[i])
                    {
                        mesafe[i]=kisaMesafe+gecici[sonraki][i];
                        once[i]=sonraki;
                    }
                    sayac++;
    }
    for(i=1;i<23;i++)
        if(i!=sehir)
        {
            printf("\n%d. sehire olan uzakligin maliyeti : %d", i, mesafe[i]);
            printf("\nYol = %d",i);

            j=i;
            do
            {
                j=once[j];
                printf(" <- %d ",j);
            }while(j!=sehir);
    }
}
void islem2(int sehirMatrisi[MAX][MAX], int sehir1, int sehir2)
{
    int gecici[MAX][MAX],mesafe[MAX],once[MAX];
    int ziyaretEdilen[MAX],sayac,kisaMesafe,sonraki,i,j;

    for(i=0;i<23;i++)
        for(j=0;j<23;j++)
            if(sehirMatrisi[i][j]==0)
               gecici[i][j]=SONSUZLUK;
            else
                gecici[i][j]=sehirMatrisi[i][j];
    for(i=0;i<23;i++)
    {
        mesafe[i]=gecici[sehir1][i];
        once[i]=sehir1;
        ziyaretEdilen[i]=0;
    }

    mesafe[sehir1]=0;
    ziyaretEdilen[sehir1]=1;
    sayac=1;

    while(sayac<22)
    {
        kisaMesafe=SONSUZLUK;

        for(i=0;i<23;i++)
            if(mesafe[i]<kisaMesafe&&!ziyaretEdilen[i])
            {
                kisaMesafe=mesafe[i];
                sonraki=i;
            }
            ziyaretEdilen[sonraki]=1;
            for(i=0;i<23;i++)
                if(!ziyaretEdilen[i])
                    if(kisaMesafe+gecici[sonraki][i]<mesafe[i])
                    {
                        mesafe[i]=kisaMesafe+gecici[sonraki][i];
                        once[i]=sonraki;
                    }
                    sayac++;
    }
    if(!(sehir1>23)&& !(sehir2>23))
    {
        for(i=0;i<23;i++)
            if(i==sehir2)
            {
                if(i!=sehir1)
                {
                    printf("Iki yol arasindaki maliyet: %d\n", mesafe[i]);
                    printf("En kisa yol : %d", i);
                    j=i;
                    do
                    {
                        j=once[j];
                        printf(" <- %d",j);
                    }while(j!=sehir1);
                }
            }
   }
}
int main()
{
    int sehirMatrisi[23][23] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 233, 191, 131, 184, 75, 225, 258, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 233, 0, 0, 0, 0, 0, 0, 0, 144, 78, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 191, 0, 0, 233, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 131, 0, 233, 0, 0, 105, 0, 0, 0, 0, 0, 112, 193, 156, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 184, 0, 0, 0, 0, 0, 310, 0, 0, 0, 0, 0, 0, 0, 245, 305, 0, 0, 0, 0, 0, 0},
                                 {0, 75, 0, 0, 105, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 225, 0, 0, 0, 310, 0, 0, 148, 0, 0, 0, 0, 0, 0, 0, 75, 0, 0, 0, 0, 0, 0},
                                 {0, 258, 0, 0, 0, 0, 0, 148, 0, 223, 0, 0, 0, 0, 0, 0, 0, 0, 242, 263, 322, 119, 348},
                                 {0, 0, 144, 0, 0, 0, 0, 0, 223, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 78, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 156, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 245, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 190, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 305, 0, 75, 0, 0, 0, 0, 0, 0, 0, 190, 0, 81, 82, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 242, 0, 0, 0, 0, 0, 0, 0, 82, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 322, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 348, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                               };
    char *sehirAdlari[22];
    sehirAdlari[0] = "Ankara";
    sehirAdlari[1] = "Eskisehir";
    sehirAdlari[2] = "Bolu";
    sehirAdlari[3] = "Cankiri";
    sehirAdlari[4] = "Kirsehir";
    sehirAdlari[5] = "Kirikkale";
    sehirAdlari[6] = "Aksaray";
    sehirAdlari[7] = "Konya";
    sehirAdlari[8] = "Afyon";
    sehirAdlari[9] = "Kutahya";
    sehirAdlari[10] = "Bilecik";
    sehirAdlari[11] = "Kastamonu";
    sehirAdlari[12] = "Karabuk";
    sehirAdlari[13] = "Corum";
    sehirAdlari[14] = "Yozgat";
    sehirAdlari[15] = "Nevsehir";
    sehirAdlari[16] = "Kayseri";
    sehirAdlari[17] = "Nigde";
    sehirAdlari[18] = "Isparta";
    sehirAdlari[19] = "Antalya";
    sehirAdlari[20] = "Karaman";
    sehirAdlari[21] = "Mersin";

    int i, j;
    for(i=1, j=0; i<23, j<22; i++, j++)
    {
        printf("%d = %s ", i, sehirAdlari[j]);
        printf("\n");

    }
    printf("\n");
    int menu;
    while(1)
    {
        int secim;
        printf("\nBir sehrin diger sehirlere olan uzaklik islemini yapmak icin 1 e \nIki sehir arasindaki mesafeyi bulma islemi icin 2 ye basiniz.");
        scanf("%d", &secim);
        switch(secim)
        {
            case 1:
                {
                    while(1)
                        {
                            int sehir;
                            printf("\nHangi sehrin diger sehirlere uzakligini bulmak istiyorsunuz?: ");
                            scanf("%d", &sehir);
                            islem1(sehirMatrisi, sehir);
                            printf("\n\nAna menuye donmek icin 3 e basiniz.");
                            printf("\nTekrar uzaklik  bulmak icin 4 e basiniz.   ");
                            scanf("%d", &menu);

                            if(menu == 3)
                                break;
                            else if(menu==4)
                                continue;
                        }
                }
                break;
            case 2:
                {
                    while(1)
                        {
                            int sehir1, sehir2;
                            printf("\nLutfen birinci sehiri giriniz: ");
                            scanf("%d", &sehir1);
                            printf("Lutfen ikinci sehiri giriniz: ");
                            scanf("%d", &sehir2);
                            islem2(sehirMatrisi, sehir1, sehir2);
                            printf("\n\nAna menuye donmek icin 3 e basiniz.");
                            printf("\nTekrar iki sehir arasi uzaklik bulmak icin 4 e basiniz.   ");
                            scanf("%d", &menu);

                            if(menu == 3)
                                break;
                            else if(menu==4)
                                continue;
                        }
                }
                break;
             default:
                 printf("Yanlis deger girdiniz.");
                 break;
         }
    }
    return 0;
}
