#include <stdio.h>
#include <string.h>
#include <math.h>

#define GEZEGEN_SAYISI 9

// Fonksiyonlar
void deney1_serbest_dusme(double *yercekim, char **gezegen_isimleri, char *bilim_adami);
void deney2_yukari_atis(double *yercekim, char **gezegen_isimleri, char *bilim_adami);
void deney3_agirlik(double *yercekim, char **gezegen_isimleri, char *bilim_adami);
void deney4_potansiyel_enerji(double *yercekim, char **gezegen_isimleri, char *bilim_adami);
void deney5_hidrostatik_basinc(double *yercekim, char **gezegen_isimleri, char *bilim_adami);
void deney6_kaldirma_kuvveti(double *yercekim, char **gezegen_isimleri, char *bilim_adami);
void deney7_sarkac_periyodu(double *yercekim, char **gezegen_isimleri, char *bilim_adami);
void deney8_ip_gerilmesi(double *yercekim, char **gezegen_isimleri, char *bilim_adami);
void deney9_asansor(double *yercekim, char **gezegen_isimleri, char *bilim_adami);
void menu_goster(char *bilim_adami);

int main() {
    /* Gezegenlerin yerçekimi ivmeleri (m/s^2)
    /* İndeks: 0=Merkür, 1=Venüs, 2=Dünya, 3=Mars, 4=Jüpiter, 5=Satürn, 6=Uranüs, 7=Neptün, 8=Plüton */
    double yercekim[GEZEGEN_SAYISI] = {3.7, 8.87, 9.81, 3.71, 24.79, 10.44, 8.69, 11.15, 0.62};
    
    // Gezegenler
    char *gezegen_isimleri[GEZEGEN_SAYISI] = {
        "Merkur", "Venus", "Dunya", "Mars", "Jupiter",
        "Saturn", "Uranus", "Neptun", "Pluton"
    };
    
    char bilim_adami[100];
    int secim;
    
    // Karakter oluşturma
    printf("==============================================\n");
    printf("   UZAY FIZIGI SIMULASYON SISTEMI\n");
    printf("==============================================\n\n");
    printf("Lutfen bilim adaminin adini giriniz: ");
    fgets(bilim_adami, sizeof(bilim_adami), stdin);
    bilim_adami[strcspn(bilim_adami, "\n")] = '\0';
    
    printf("\nHosgeldiniz, %s!\n", bilim_adami);
    printf("Uzay fizigi simulasyonunuz baslatiliyor ucusa hazirlan 5 4 3 2 1...\n\n");
    
    
    while (1) {
        menu_goster(bilim_adami);
        printf("Seciminizi giriniz: ");
        scanf("%d", &secim);
        
        // -1 degeri girilince programi sonlandirmaya yarar.
        if (secim == -1) {
            printf("\n==============================================\n");
            printf("Tesekkurler, %s!\n", bilim_adami);
            printf("Simulasyon sistemi kapatiliyor...\n");
            printf("==============================================\n");
            break;
        }
        
        // switch case yapısı ile deney seçimi
        switch (secim) {
            case 1:
                deney1_serbest_dusme(yercekim, gezegen_isimleri, bilim_adami);
                break;
            case 2:
                deney2_yukari_atis(yercekim, gezegen_isimleri, bilim_adami);
                break;
            case 3:
                deney3_agirlik(yercekim, gezegen_isimleri, bilim_adami);
                break;
            case 4:
                deney4_potansiyel_enerji(yercekim, gezegen_isimleri, bilim_adami);
                break;
            case 5:
                deney5_hidrostatik_basinc(yercekim, gezegen_isimleri, bilim_adami);
                break;
            case 6:
                deney6_kaldirma_kuvveti(yercekim, gezegen_isimleri, bilim_adami);
                break;
            case 7:
                deney7_sarkac_periyodu(yercekim, gezegen_isimleri, bilim_adami);
                break;
            case 8:
                deney8_ip_gerilmesi(yercekim, gezegen_isimleri, bilim_adami);
                break;
            case 9:
                deney9_asansor(yercekim, gezegen_isimleri, bilim_adami);
                break;
            default:
                printf("\nGecersiz secim! Lutfen gecerli bir deney numarasi giriniz.\n\n");
        }
    }
    
    return 0;
}

// Ana menü
void menu_goster(char *bilim_adami) {
    printf("==============================================\n");
    printf("   %s - Deney Menusu\n", bilim_adami);
    printf("==============================================\n");
    printf("1.  Serbest Dusme Deneyi\n");
    printf("2.  Yukari Atis Deneyi\n");
    printf("3.  Agirlik Deneyi\n");
    printf("4.  Kutlecekimsel Potansiyel Enerji Deneyi\n");
    printf("5.  Hidrostatik Basinc Deneyi\n");
    printf("6.  Arsimet Kaldirma Kuvveti Deneyi\n");
    printf("7.  Basit Sarkac Periyodu Deneyi\n");
    printf("8.  Sabit Ip Gerilmesi Deneyi\n");
    printf("9.  Asansor Deneyi\n");
    printf("-1. Programi Kapat\n");
    printf("==============================================\n");
}

// Deney 1: Serbest Düşme ( h = 0.5 * g * t^2  )
void deney1_serbest_dusme(double *yercekim, char **gezegen_isimleri, char *bilim_adami) {
    double sure, mesafe;
    int i;
    
    printf("\n--- DENEY 1: SERBEST DUSME ---\n");
    printf("%s, lutfen dusme suresini giriniz (saniye): ", bilim_adami);
    scanf("%lf", &sure);
    
    // Negatif deger mutlak degere cevirme
    sure = (sure < 0) ? -sure : sure;
    
    printf("\n%.2f saniye sonraki serbest dusme sonuclari:\n", sure);
    printf("----------------------------------------------\n");
    
    // Tum gezegenler için hesaplama
    for (i = 0; i < GEZEGEN_SAYISI; i++) {
        mesafe = 0.5 * (*(yercekim + i)) * sure * sure;
        printf("%s'te:\n", *(gezegen_isimleri + i));
        printf("  %.2f saniye sonra kat edilen mesafe %.2f metredir.\n\n", 
               sure, mesafe);
    }
}

// Deney 2: Yukarı Atış ( h_max = v0^2 / (2*g) )
void deney2_yukari_atis(double *yercekim, char **gezegen_isimleri, char *bilim_adami) {
    double hiz, maksimum_yukseklik;
    int i;
    
    printf("\n--- DENEY 2: YUKARI ATIS ---\n");
    printf("%s, lutfen baslangic hizini giriniz (m/s): ", bilim_adami);
    scanf("%lf", &hiz);
    
    hiz = (hiz < 0) ? -hiz : hiz;
    
    printf("\n%.2f m/s baslangic hiziyla yukari atilan cisim:\n", hiz);
    printf("----------------------------------------------\n");
    
    for (i = 0; i < GEZEGEN_SAYISI; i++) {
        maksimum_yukseklik = (hiz * hiz) / (2.0 * (*(yercekim + i)));
        printf("%s'te:\n", *(gezegen_isimleri + i));
        printf("  Maksimum cikabilecegi yukseklik %.2f metredir.\n\n", maksimum_yukseklik);
    }
}

// Deney 3: Ağırlık ( G = m * g )
void deney3_agirlik(double *yercekim, char **gezegen_isimleri, char *bilim_adami) {
    double kutle, agirlik;
    int i;
    
    printf("\n--- DENEY 3: AGIRLIK HESAPLAMA ---\n");
    printf("%s, lutfen cismin kutlesini giriniz (kg): ", bilim_adami);
    scanf("%lf", &kutle);
    
    kutle = (kutle < 0) ? -kutle : kutle;
    
    printf("\n%.2f kg kutleli cismin agirligi:\n", kutle);
    printf("----------------------------------------------\n");
    
    for (i = 0; i < GEZEGEN_SAYISI; i++) {
        agirlik = kutle * (*(yercekim + i));
        printf("%s'te:\n", *(gezegen_isimleri + i));
        printf("  Cismin agirligi %.2f Newton'dur.\n\n", agirlik);
    }
}

// Deney 4: Kütleçekimsel Potansiyel Enerji ( Ep = m * g * h )
void deney4_potansiyel_enerji(double *yercekim, char **gezegen_isimleri, char *bilim_adami) {
    double kutle, yukseklik, potansiyel_enerji;
    int i;
    
    printf("\n--- DENEY 4: KUTLECEKIMSEL POTANSIYEL ENERJI ---\n");
    printf("%s, lutfen cismin kutlesini giriniz (kg): ", bilim_adami);
    scanf("%lf", &kutle);
    printf("Lutfen yuksekligi giriniz (metre): ");
    scanf("%lf", &yukseklik);
    
    kutle = (kutle < 0) ? -kutle : kutle;
    yukseklik = (yukseklik < 0) ? -yukseklik : yukseklik;
    
    printf("\n%.2f kg kutle ve %.2f m yukseklik icin:\n", kutle, yukseklik);
    printf("----------------------------------------------\n");
  
    for (i = 0; i < GEZEGEN_SAYISI; i++) {
        potansiyel_enerji = kutle * (*(yercekim + i)) * yukseklik;
        printf("%s'te:\n", *(gezegen_isimleri + i));
        printf("  Kutlecekimsel potansiyel enerji %.2f Joule'dur.\n\n", potansiyel_enerji);
    }
}

// Deney 5: Hidrostatik Basınç ( P = rho * g * h )
void deney5_hidrostatik_basinc(double *yercekim, char **gezegen_isimleri, char *bilim_adami) {
    double yogunluk, derinlik, basinc;
    int i;
    
    printf("\n--- DENEY 5: HIDROSTATIK BASINC ---\n");
    printf("%s, lutfen sivi yogunlugunu giriniz (kg/m^3): ", bilim_adami);
    scanf("%lf", &yogunluk);
    printf("Lutfen derinligi giriniz (metre): ");
    scanf("%lf", &derinlik);
    
    yogunluk = (yogunluk < 0) ? -yogunluk : yogunluk;
    derinlik = (derinlik < 0) ? -derinlik : derinlik;
    
    printf("\n%.2f kg/m^3 yogunlukta sivi ve %.2f m derinlikte:\n", yogunluk, derinlik);
    printf("----------------------------------------------\n");
    
    for (i = 0; i < GEZEGEN_SAYISI; i++) {
        basinc = yogunluk * (*(yercekim + i)) * derinlik;
        printf("%s'te:\n", *(gezegen_isimleri + i));
        printf("  Hidrostatik basinc %.2f Pascal'dir.\n\n", basinc);
    }
}

// Deney 6: Arşimet Kaldırma Kuvveti ( Fk = rho * g * V )
void deney6_kaldirma_kuvveti(double *yercekim, char **gezegen_isimleri, char *bilim_adami) {
    double yogunluk, hacim, kaldirma_kuvveti;
    int i;
    
    printf("\n--- DENEY 6: ARSIMET KALDIRMA KUVVETI ---\n");
    printf("%s, lutfen sivi yogunlugunu giriniz (kg/m^3): ", bilim_adami);
    scanf("%lf", &yogunluk);
    printf("Lutfen batan hacmi giriniz (m^3): ");
    scanf("%lf", &hacim);
    
    yogunluk = (yogunluk < 0) ? -yogunluk : yogunluk;
    hacim = (hacim < 0) ? -hacim : hacim;
    
    printf("\n%.2f kg/m^3 yogunlukta sivi ve %.2f m^3 hacim icin:\n", yogunluk, hacim);
    printf("----------------------------------------------\n");
    
    for (i = 0; i < GEZEGEN_SAYISI; i++) {
        kaldirma_kuvveti = yogunluk * hacim * (*(yercekim + i));
        printf("%s'te:\n", *(gezegen_isimleri + i));
        printf("  Kaldirma kuvveti %.2f Newton'dur.\n\n", kaldirma_kuvveti);
    }
}

// Deney 7: Basit Sarkaç Periyodu ( T = 2*pi*sqrt(L/g) )
void deney7_sarkac_periyodu(double *yercekim, char **gezegen_isimleri, char *bilim_adami) {
    double uzunluk, periyot;
    int i;
    const double PI = 3.14159265359;
    
    printf("\n--- DENEY 7: BASIT SARKAC PERIYODU ---\n");
    printf("%s, lutfen sarkac uzunlugunu giriniz (metre): ", bilim_adami);
    scanf("%lf", &uzunluk);
    
    uzunluk = (uzunluk < 0) ? -uzunluk : uzunluk;
    
    printf("\n%.2f metre uzunlugundaki sarkac icin:\n", uzunluk);
    printf("----------------------------------------------\n");
    
    for (i = 0; i < GEZEGEN_SAYISI; i++) {
        periyot = 2.0 * PI * sqrt(uzunluk / (*(yercekim + i)));
        printf("%s'te:\n", *(gezegen_isimleri + i));
        printf("  Sarkacin saliniminperiyodu %.2f saniyedir.\n\n", periyot);
    }
}

// Deney 8: Sabit İp Gerilmesi ( T = m * g )
void deney8_ip_gerilmesi(double *yercekim, char **gezegen_isimleri, char *bilim_adami) {
    double kutle, gerilme;
    int i;
    
    printf("\n--- DENEY 8: SABIT IP GERILMESI ---\n");
    printf("%s, lutfen asili cismin kutlesini giriniz (kg): ", bilim_adami);
    scanf("%lf", &kutle);
    
    kutle = (kutle < 0) ? -kutle : kutle;
    
    printf("\n%.2f kg kutleli cisim icin:\n", kutle);
    printf("----------------------------------------------\n");
    
    for (i = 0; i < GEZEGEN_SAYISI; i++) {
        gerilme = kutle * (*(yercekim + i));
        printf("%s'te:\n", *(gezegen_isimleri + i));
        printf("  Ipteki gerilme kuvveti %.2f Newton'dur.\n\n", gerilme);
    }
}

// Deney 9: Asansör ( N = m * (g + a) veya N = m * (g - a) )
void deney9_asansor(double *yercekim, char **gezegen_isimleri, char *bilim_adami) {
    double kutle, ivme, etkin_agirlik;
    int i;
    
    printf("\n--- DENEY 9: ASANSOR DENEYI ---\n");
    printf("%s, lutfen kisinin kutlesini giriniz (kg): ", bilim_adami);
    scanf("%lf", &kutle);
    printf("Lutfen asansorun ivmesini giriniz (m/s^2):\n");
    printf("(Pozitif = yukari ivmeleniyor, Negatif = asagi ivmeleniyor): ");
    scanf("%lf", &ivme);
    
    kutle = (kutle < 0) ? -kutle : kutle;
    /* Not: İvme pozitif veya negatif olabilir, mutlak değere çevrilmez */
    
    printf("\n%.2f kg kutle ve %.2f m/s^2 ivme icin:\n", kutle, ivme);
    printf("----------------------------------------------\n");
    
    for (i = 0; i < GEZEGEN_SAYISI; i++) {
        etkin_agirlik = kutle * ((*(yercekim + i)) + ivme);
        printf("%s'te:\n", *(gezegen_isimleri + i));
        printf("  Etkin agirlik %.2f Newton'dur.\n\n", etkin_agirlik);
    }
}
